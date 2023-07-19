#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "items.h"

// given struct for rooms
typedef struct Room
{
    char *name;
    struct Room *North;
    struct Room *South;
    struct Room *East;
    struct Room *West;
    struct item *itemlist;

} Room;

extern void setitems(Room *x);
extern void printboard(Room *x);
extern void lookroom(Room *x);
extern void setName(Room *rptr);
extern void swap(Room *a, Room *b);
extern void shuffle(Room *c);
extern void setRooms(Room *rptr);
extern void funclook(Room *a);
extern Room* funcgo(Room *curr, char *direction);
