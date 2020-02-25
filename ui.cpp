#include <stdio.h>
#include <iostream>

#include "ui.h"

char draw_wall[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char draw_ghost[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char draw_champion[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char draw_pill[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char draw_empty[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void print_part(char draw[4][7], int part)
{
    printf("%s", draw[part]);
}

void print_map(MAP* m)
{
    for(int i = 0; i < m->lines; i++){
        for(int part = 0; part < 4; part++){
            for(int j = 0; j < m->columns; j++){
                switch (m->matrix[i][j]){
                    case GHOST:
                        print_part(draw_ghost, part);
                        break;
                    case CHAMPION:
                        print_part(draw_champion, part);
                        break;
                    case PILL:
                        print_part(draw_pill, part);
                        break;
                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        print_part(draw_wall, part);
                        break;
                    case EMPTY:
                        print_part(draw_empty, part);
                        break;
                  }
            }
            std::cout << "\n";
        }
        
    }
}