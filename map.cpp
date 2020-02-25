#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

void read_map(MAP* m)
{
    FILE* f;
    f = fopen("map.txt", "r");
    if(f == 0){
        std::cout << "Error reading map.\n" << std::endl;
        exit(1);
    }

    fscanf(f, "%d %d", &(m->lines), &(m->columns));
    alocate_map(m);

    for(int i = 0; i < m->lines; i++){
        fscanf(f, "%s", m->matrix[i]);
    }

    fclose(f);
}

void alocate_map(MAP* m)
{
    m->matrix = (char **)malloc(sizeof(char*) * m->lines);

    for(int i = 0; i < m->lines; i++) {
        m->matrix[i] = (char *)malloc(sizeof(char) * m->columns + 1);
    }   
}

void copy_map(MAP* destiny, MAP* origin)
{
    destiny->lines   = origin->lines;
    destiny->columns = origin->columns;

    alocate_map(destiny);

    for(int i = 0; i < origin->lines; i++){
        strcpy(destiny->matrix[i], origin->matrix[i]);
    }
}

void free_map(MAP* m)
{
    for(int i = 0; i < m->lines; i++){
        free(m->matrix[i]);
    }

    free(m->matrix);
}

// void print_map(MAP* m)
// {
//     for(int i = 0; i < m->lines; i++){
//         std::cout << m->matrix[i] << std::endl;
//     }
// }

bool find_map(MAP* m, POSITION* p, char c)
{
    for(int i = 0; i < m->lines; i++){
        for(int j = 0; j < m->columns; j++){
            if(m->matrix[i][j] == c){
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0; // map not found
}

int can_move(MAP* m, char character, int x, int y)
{
    return is_valid(m, x, y) && !is_wall(m, x, y) && !is_character(m, character, x, y);
}

int is_valid(MAP* m, int x, int y)
{
    if(x >= m->lines || x < 0) // or added to test memory error
        return 0;
    if(y >= m->columns || y < 0)
        return 0;

    return 1;
}

int is_character(MAP* m, char character, int x, int y)
{
    return m->matrix[x][y] == character;
}

int is_wall(MAP* m, int x, int y)
{
    return m->matrix[x][y] == VERTICAL_WALL || m->matrix[x][y] == HORIZONTAL_WALL;
}

void move_on_map(MAP* m, int x_origin, int y_origin, int x_destiny, int y_destiny)
{
    char character = m->matrix[x_origin][y_origin];
    m->matrix[x_destiny][y_destiny] = character;
    m->matrix[x_origin][y_origin] = EMPTY;
}

// int is_empty(MAP* m, int x, int y)
// {
//     return m->matrix[x][y] == EMPTY;
// }