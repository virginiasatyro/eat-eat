#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "eat-eat.h"

char** map;
int lines = 5;
int columns = 10;

void alocate_map()
{
    //  map = malloc(sizeof(char*) * lines);
    map = (char **)malloc(lines * sizeof(char *));


    for(int i = 0; i < lines; i++){
        map[i] = (char *)malloc(sizeof(char) * columns + 1);
    }
}

void read_map()
{
    FILE* f;
    f = fopen("map.txt", "r");

    if(f == 0){
        std::cout << "Error reading map!" << std::endl;
        exit(1);
    }

    fscanf(f, "%d %d", &lines, &columns);
    alocate_map();

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", map[i]);
    }

    fclose(f);
}

void free_map()
{
    for(int i = 0; i < lines; i++){
        free(map[i]);
    }
    free(map);
}

int main(void)
{
    std::cout << "Wencome to eat-eat game!" << std::endl;

    read_map();

    for(int i = 0; i < lines; i++){
        std::cout << map[i] << std::endl;
    }

    free_map();
}