struct map{
    char** matrix;
    int lines;
    int columns;
};

typedef struct map MAP;

void alocate_map(MAP* m);

void read_map(MAP* m);

void free_map(MAP* m);

void print_map(MAP* m);

struct position{
    int x;
    int y;
};

typedef struct position POSITION;

void find_map(MAP* m, POSITION* p, char c);
