#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "map.h"

void read_map(MAP* m)
{
    FILE* f;
    f = fopen("map.txt", "r");
    if(f == 0){
        std::cout << "Error reading map" << std::endl;
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

void free_map(MAP* m)
{
    for(int i = 0; i < m->lines; i++){
        free(m->matrix[i]);
    }

    free(m->matrix);
}

void print_map(MAP* m)
{
    for(int i = 0; i < m->lines; i++){
        std::cout << m->matrix[i] << std::endl;
    }
}

void find_map(MAP* m, POSITION* p, char c)
{
    for(int i = 0; i < m->lines; i++){
        for(int j = 0; j < m->columns; j++){
            if(m->matrix[i][j] == c){
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}