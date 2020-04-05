#include <iostream>

using namespace std;

#include "eat-eat.h"

char** map;
int lines;
int columns;

void readMap()
{
    FILE* f;
    f = fopen("map.txt", "r");
    if(f == 0)
    {
        cout << "Error reading map!" << endl;
        exit(1);
    }

    fscanf(f, "%d %d", &lines, &columns);
    alocateMap();

    for(int i = 0; i < 5; i++)
        fscanf(f, "%s", map[i]);

    fclose(f);
}

void alocateMap()
{
    map = (char**)malloc(sizeof(char*) * lines);

    for(int i = 0; i < lines; i++)
        map[i] = (char*)malloc(sizeof(char) * columns + 1);
}

void freeMap()
{
    for(int i = 0; i < lines; i++)
        free(map[i]);
    
    free(map);
}

int main()
{
    readMap();

    for(int i = 0; i < lines; i++)
        cout << map[i] << endl;

    freeMap();

    return 0;
}