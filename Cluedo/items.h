#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include "rooms.h"

typedef struct item
{
    char *name;
    struct item *next;
} item;

extern void functake(item *x, char *y);

extern void funcdrop(item *x, char *y);

extern void itemscount(item *x);
