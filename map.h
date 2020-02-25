#ifndef _MAP_H
#define _MAP_H

#define CHAMPION        '@'
#define EMPTY           '.'
#define VERTICAL_WALL   '|'
#define HORIZONTAL_WALL '-'
#define GHOST           'G'
#define PILL            'P'

struct map{
    char** matrix;
    int lines;
    int columns;
};

struct position{
    int x;
    int y;
};

typedef struct map MAP;

typedef struct position POSITION;

void free_map(MAP* m);

void read_map(MAP* m);

void alocate_map(MAP* m);

// void print_map(MAP* m);

bool find_map(MAP* m, POSITION* p, char c);


int is_valid(MAP* m, int x, int y);

int is_empty(MAP* m, int x, int y);

int is_wall(MAP* m, int x, int y);

void move_on_map(MAP* m, int x_origin, int y_origin, int x_destiny, int y_destiny);

void copy_map(MAP* destiny, MAP* origin);

int can_move(MAP* m, char character, int x, int y);

int is_character(MAP* m, char character, int x, int y);

#endif // _MAP_H