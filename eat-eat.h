#ifndef _EAT_EAT_H
#define _EAT_EAT_H

#define UP    'w'
#define DOWN  's'
#define RIGHT 'd'
#define LEFT  'a'
#define BOMB  'b'

int game_over();

void move(char direction);

int is_direction(char direction);

void ghosts();

// int where_ghost_go(int x_current, int y_current, int* x_destiny, int* y_destiny);

void explode_pill();

void explode_pill_2(int x, int y, int sum_x, int sum_y, int num);

#endif // _EAT_EAT_H