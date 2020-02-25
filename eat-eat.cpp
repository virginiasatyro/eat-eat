#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "eat-eat.h"
#include "map.h"

MAP m;
POSITION champion;

int game_over()
{
    POSITION pos;

    int lose_game = !find_map(&m, &pos, CHAMPION);
    int win_game  = !find_map(&m, &pos, GHOST);

    return win_game || lose_game;
}

int is_direction(char direction)
{
    return direction == UP || direction == DOWN || direction == RIGHT || direction == LEFT;
}

void move(char direction)
{
    if(!is_direction(direction))
        return;

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

int main()
{
    read_map(&m);
    find_map(&m, &champion, '@');

    do{
        print_map(&m);

        char move_direction;
        std::cin >> &move_direction;

        move(move_direction);
        ghosts();
    }while(!game_over());

    free_map(&m);    
}