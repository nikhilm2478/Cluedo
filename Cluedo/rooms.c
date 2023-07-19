#include "rooms.h"

//testing function                                                          
void printboard(Room *x)
{
  for (int i=0; i<9;i++)
    {
    //set directions to NULL, then check if it is NULL or not before looking for name
    if ((x+i)->North != NULL) {printf("for %s N is %s\n",(x+i)->name,(x+i)->North->name);}
    else {printf("for %s N is NULL\n", (x+i)->name);}
    if ((x+i)->South != NULL) {printf("for %s S is %s\n",(x+i)->name,(x+i)->South->name);}
    else {printf("for %s S is NULL\n", (x+i)->name);}
    if ((x+i)->West != NULL) {printf("for %s W is %s\n",(x+i)->name,(x+i)->West->name);}
    else {printf("for %s W is NULL\n", (x+i)->name);}
    if ((x+i)->East != NULL) {printf("for %s E is %s\n",(x+i)->name,(x+i)->East->name);}
    else {printf("for %s E is NULL\n", (x+i)->name);}
  }
}

//sets items for each room
void setitems(Room *rptr) {
   char *itemnames[6] = {"candle", "dagger", "pipe", "gun", "rope", "hammer"};
   char *charnames[5] = {"Walter","Jesse","Saul","Mike","Gus"};
   item a;
   item *aptr = &a;
   aptr->name = itemnames[0];
   item b;
   item *bptr = &b;
   bptr->name = itemnames[1];
   item c;
   item *cptr = &c;
   cptr->name = itemnames[2];
   item d;
   item *dptr = &d;
   dptr->name = itemnames[3];
   item e;
   item *eptr = &e;
   eptr->name = itemnames[4];
   item f;
   item *fptr = &f;
   fptr->name = itemnames[5];
   item g;
   item *gptr = &g;
   gptr->name = charnames[0];
   item h;
   item *hptr = &h;
   hptr->name = charnames[1];
   item i;
   item *iptr = &i;
   iptr->name =	charnames[2];
   item j;
   item *jptr = &j;
   jptr->name =	charnames[3];
   item k;
   item *kptr = &k;
   kptr->name =	charnames[4];
   
   (rptr)->itemlist = aptr;
   (rptr+1)->itemlist = bptr;
   (rptr+2)->itemlist = cptr;
   (rptr+3)->itemlist = dptr;
   (rptr+4)->itemlist = eptr;
   (rptr+5)->itemlist = fptr;
   (rptr+6)->itemlist = gptr;
   (rptr+7)->itemlist = hptr;
   (rptr+8)->itemlist = iptr;
}

//prints room name and name and direction of adjascent rooms                   
void lookroom(Room *x)
{
  if (x->itemlist != NULL)
  {
    printf("this room has item: %s\n",x->itemlist->name);
  }
  else
  {
    printf("this room has no items\n");
  }
    if ((x)->North != NULL)
    {
        printf("for %s N is %s\n", (x)->name, (x)->North->name);
    }
    else
    {
        printf("for %s N is NULL\n", (x)->name);
    }
    if ((x)->South != NULL)
    {
        printf("for %s S is %s\n", (x)->name, (x)->South->name);
    }
    else
    {
        printf("for %s S is NULL\n", (x)->name);
    }
    if ((x)->West != NULL)
    {
        printf("for %s W is %s\n", (x)->name, (x)->West->name);
    }
    else
    {
        printf("for %s W is NULL\n", (x)->name);
    }
    if ((x)->East != NULL)
    {
        printf("for %s E is %s\n", (x)->name, (x)->East->name);
    }
    else
    {
        printf("for %s E is NULL\n", (x)->name);
    }
}

//sets the names for the rooms on the board                   
void setName(Room *rptr)
{
    int i;
    char *names[9] = {"kitchen", "ballroom", "conservatory", "dining", "billiards", "library", "lounge", "hall", "study"};
    char nam0[] = "";
    char *n0 = nam0;
    for (i = 0; i < 9; i++)
    {
        (rptr + i)->name = nam0;
        (rptr + i)->name = names[i];                                           
    }
}

//sets the rooms to each of the directions of a room                           
//sets to NULL, if there is no room in a certain direction                            
void setRooms(Room *rptr)
{
    // setting items and characters
    //setting rooms in each directiokn
    rptr->East = rptr + 1;
    rptr->South = rptr + 3;
    rptr->North = NULL;
    rptr->West = NULL;
    (rptr + 1)->West = rptr;
    (rptr + 1)->East = rptr + 2;
    (rptr + 1)->South = rptr + 4;
    (rptr + 1)->North = NULL;
    (rptr + 2)->West = rptr + 1;
    (rptr + 2)->South = rptr + 5;
    (rptr + 2)->North = NULL;
    (rptr + 2)->East = NULL;
    (rptr + 3)->East = rptr + 4;
    (rptr + 3)->South = rptr + 6;
    (rptr + 3)->North = rptr;
    (rptr + 3)->West = NULL;
    (rptr + 4)->West = rptr + 3;
    (rptr + 4)->East = rptr + 5;
    (rptr + 4)->South = rptr + 7;
    (rptr + 4)->North = rptr + 1;
    (rptr + 5)->West = rptr + 4;
    (rptr + 5)->North = rptr + 2;
    (rptr + 5)->South = rptr + 8;
    (rptr + 5)->East = NULL;
    (rptr + 6)->East = rptr + 7;
    (rptr + 6)->North = rptr + 3;
    (rptr + 6)->South = NULL;
    (rptr + 6)->West = NULL;
    (rptr + 7)->East = rptr + 8;
    (rptr + 7)->West = rptr + 6;
    (rptr + 7)->North = rptr + 4;
    (rptr + 7)->South = NULL;
    (rptr + 8)->West = rptr + 7;
    (rptr + 8)->North = rptr + 5;
    (rptr + 8)->South = NULL;
    (rptr + 8)->East = NULL;
}

//changes current room to room in the direction inputted
Room *funcgo(Room *curr, char *direction)
{
    if (strcasecmp("north", direction) == 0)
    {
        if (curr->North == NULL)
        {
            printf("you cannot go there\n");
            return curr;
        }
        curr = curr->North;
        printf("You are in room %s\n", curr->name);
        return curr;
    }
    else if (strcasecmp("south", direction) == 0)
    {
        if (curr->South == NULL)
        {
            printf("you cannot go there\n");
            return curr;
        }
        curr = curr->South;
        printf("You are in room %s\n", curr->name);
        return curr;
    }
    else if (strcasecmp("west", direction) == 0)
    {
        if (curr->West == NULL)
        {
            printf("you cannot go there\n");
            return curr;
        }
        curr = curr->West;
        
        printf("You are in room %s\n", curr->name);
        return curr;
    }
    else if (strcasecmp("east", direction) == 0)
    {
        if (curr->East == NULL)
        {
            printf("you cannot go there\n");
            return curr;
        }
        curr = curr->East;
        printf("You are in %s\n", curr->name);
        return curr;
    }
    else
    {
        printf("try again, direction not clear\n");
        return curr;
    }
};
