#ifndef _EAT_EAT
#define _EAT_EAT

class Map
{
private:
    char** map;
    unsigned int lines;
    unsigned int columns;
    unsigned int map_number;

public:
    void set_lines(unsigned int);
    void set_columns(unsigned int);
    void set_map_number(unsigned int);

    unsigned int get_lines();
    unsigned int get_columns();
    unsigned int get_map_number();

    void read_map();
    void alocate_map();
};

// void freeMap();

#endif // _EAT_EAT