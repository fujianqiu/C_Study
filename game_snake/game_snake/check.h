#include "public.h"
#include "food.h"
#include "snake.h"
#include "wall.h"
#ifndef __CHECK_PEN__
#define __CHECK_PEN__
int check_penalty_box(snake *snake_head, wall *wall_head,coordinate *xy);
int check_food(coordinate *xy, food *all_food);
#endif