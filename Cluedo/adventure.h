#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "rooms.h"
//#include "items.h"

extern bool parser(Room *x, Room *curr, item *y, char *input);
extern bool execClue(char string[], item *itemList);
extern void generateAnswers();
