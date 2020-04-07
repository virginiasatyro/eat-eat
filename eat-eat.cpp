#include <iostream>

using namespace std;

#include "eat-eat.h"

void Map::set_lines(unsigned int lines)
{
    this->lines = lines;
}

void Map::set_columns(unsigned int columns)
{
    this->columns = columns;
}

void Map::set_map_number(unsigned int map_number)
{
    this->map_number = map_number;
}

unsigned int Map::get_lines()
{
    return lines;
}

unsigned int Map::get_columns()
{
    return columns;
}

unsigned int Map::get_map_number()
{
    return map_number;
}

void Map::read_map()
{
    FILE* file;
    file = fopen("map.txt", "r");

    if(file == 0)
    {
        cout << "Error reading file!" << endl;
        exit(1);
    }

    unsigned int aux_lines, aux_columns;
    fscanf(file, "%d %d", &aux_lines, &aux_columns);
    set_lines(aux_lines);
    set_columns(aux_columns);
}

void Map::alocate_map()
{
    map = (char**)malloc(sizeof(char*) * lines);

    for(int i = 0; i < lines; i++)
        map[i] = (char*)malloc(sizeof(char) * columns + 1);
}

// void readMap()
// {
//     FILE* f;
//     f = fopen("map.txt", "r");
//     if(f == 0)
//     {
//         cout << "Error reading map!" << endl;
//         exit(1);
//     }

//     fscanf(f, "%d %d", &lines, &columns);
//     alocateMap();

//     for(int i = 0; i < 5; i++)
//         fscanf(f, "%s", map[i]);

//     fclose(f);
// }

// void alocateMap()
// {
//     map = (char**)malloc(sizeof(char*) * lines);

//     for(int i = 0; i < lines; i++)
//         map[i] = (char*)malloc(sizeof(char) * columns + 1);
// }

// void freeMap()
// {
//     for(int i = 0; i < lines; i++)
//         free(map[i]);
    
//     free(map);
// }

int main()
{
    Map map;

    map.read_map();
    cout << "Columns: " << map.get_columns() << endl;
    cout << "Lines: " << map.get_lines() << endl;

    // readMap();

    // for(int i = 0; i < lines; i++)
    //     cout << map[i] << endl;

    // freeMap();

    return 0;
}