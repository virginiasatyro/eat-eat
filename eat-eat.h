#ifndef _EAT_EAT
#define _EAT_EAT

class Map
{
private:
    char** map;
    unsigned int lines;
    unsigned int columns;

public:
    void set_lines(unsigned int);
    void set_columns(unsigned int);
    unsigned int get_lines();
    unsigned int get_columns();

    void read_map();
};



// void alocateMap();


// void freeMap();

#endif // _EAT_EAT