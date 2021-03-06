#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "eat-eat.h"
#include "map.h"
#include "ui.h"

MAP m;
POSITION champion;
int pill = 0;

int game_over()
{
    POSITION pos;

    int win  = !find_map(&m, &pos, CHAMPION);
    int lose = !find_map(&m, &pos, GHOST);

    return win || lose;
}

int is_direction(char direction)
{
    return direction == UP || direction == DOWN || direction == RIGHT || direction == LEFT;
}

void move(char direction)
{
    // if(!is_direction(direction))
    //     return;

    int next_x = champion.x;
    int next_y = champion.y;

    switch (direction)
    {
        case UP:
            next_x--;
            break;
        case DOWN:
            next_x++;
            break;
        case RIGHT:
            next_y++;
            break;
        case LEFT:
            next_y--;
            break;
    }

    if(!can_move(&m, CHAMPION, next_x, next_y))
        return;

    if(is_character(&m, PILL, next_x, next_y)){
        pill = 1;
    }

    move_on_map(&m, champion.x, champion.y, next_x, next_y);
    champion.x = next_x;
    champion.y = next_y;
}

int where_ghost_go(int x_current, int y_current, int* x_destiny, int* y_destiny)
{
    int options[4][2] = {
        {x_current    , y_current + 1},
        {x_current + 1, y_current},
        {x_current    , y_current - 1},
        {x_current - 1, y_current}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int position = rand() % 4;

        if(can_move(&m, GHOST, options[position][0], options[position][1])){
            *x_destiny = options[position][0];
            *y_destiny = options[position][1];
            return 1;
        }
    }
    return 0;
}

void ghosts()
{
    MAP copy;

    copy_map(&copy, &m);

    for(int i = 0; i < copy.lines; i++){
        for(int j = 0; j < copy.columns; j++){
            if(copy.matrix[i][j] == GHOST){
                int x_destiny;
                int y_destiny;

                int found = where_ghost_go(i, j, &x_destiny, &y_destiny);

                if(found){
                    move_on_map(&m, i, j, x_destiny, y_destiny);
                }
            }
        }
    }
    free_map(&copy);
}

void explode_pill_2(int x, int y, int sum_x, int sum_y, int num)
{
    if(num == 0) return;

    int new_x = x + sum_x;
    int new_y = y + sum_y;

    if(!is_valid(&m, new_x, new_y)) return;
    if(is_wall(&m, new_x, new_y)) return;

    m.matrix[new_x][new_y] = EMPTY;
    explode_pill_2(new_x, new_y, sum_x, sum_y, num - 1);
}

void explode_pill()
{
    if(!pill) return;

    explode_pill_2(champion.x, champion.y,  0,  1, 3);
    explode_pill_2(champion.x, champion.y,  0, -1, 3);
    explode_pill_2(champion.x, champion.y,  1,  0, 3);
    explode_pill_2(champion.x, champion.y, -1,  0, 3);

    pill = 0;
}

int main()
{
    read_map(&m);
    find_map(&m, &champion, CHAMPION);

    do{
        std::cout << "Pill: " << (pill ? "yes" : "no") << "\n" << std::endl;
        print_map(&m);

        char move_direction;
        std::cin >> &move_direction;

        if(is_direction(move_direction)) move(move_direction);

        if(move_direction == BOMB) explode_pill();

        ghosts();

    }while(!game_over());

    std::cout << "\n\n G A M E  O V E R\n\n" << std::endl;

    free_map(&m);    
}
