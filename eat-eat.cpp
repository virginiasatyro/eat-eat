#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "eat-eat.h"
#include "map.h"

MAP m;
POSITION champion;

int game_over()
{
    return 0;
}

void move(char direction)
{
    m.matrix[champion.x][champion.y] = '.';

    switch (direction)
    {
        case 'a':
            m.matrix[champion.x][champion.y - 1] = '@';
            champion.y--;
            break;
        case 'w':
            m.matrix[champion.x - 1][champion.y] = '@';
            champion.x--;
            break;
        case 's':
            m.matrix[champion.x + 1][champion.y] = '@';
            champion.x++;
            break;
        case 'd':
            m.matrix[champion.x][champion.y + 1] = '@';
            champion.y++;
            break;
    }
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
    }while(!game_over());

    free_map(&m);    
}