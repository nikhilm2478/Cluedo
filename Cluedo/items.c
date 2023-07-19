#include "items.h"

//add items to a linked list
void functake(item *x, char *y){
  int i =1;
  //char *ycpy = "";
  //strcpy(ycpy, y);
  if (*x[0].name == '\0') {
    strcpy(x->name ,  y);
  }
  else {
    while (*x[i].name != '\0') {
      i++;
    }
    strcpy(x[i].name , y);
  }
}

//drop items from a linked list
void funcdrop(item *x, char *y){ 
  int i=1;
  char *z = x->name;
  if (strcasecmp(x[0].name,y) == 0) {
    int j = 0;
    while(*x[j+1].name != '\0') {
      (x+j)->name = (x+j+1)->name;
    }
  }
  else {
  while (*x[i].name != '\0'){
    if (strcasecmp(x[i].name,y) == 0) {
      i--;
      (x+i)->next = (x+1)->next->next;
      free((x+i)->next);
      return;
    }
  }
  }
}

//prints items in a linked list
void itemscount(item *x) { 
  int i = 0;
  while (*x[i].name != '\0')  {
    printf("item %d is %s\n",i+1,x[i].name);
    i++;
  }
}

/*
int main () {
  item a;
  item *aptr = &a;
  char nam[] = "cow";
  char *n = nam;
  aptr->name = n;

  item b;
  item *bptr = &b;
  char na[] = "cat";
  char *nn = na;
  bptr->name = nn;

  item *itemlist = (item *) malloc(12*sizeof(item));
  int x;
  for (x = 0; x < 12; x++){
        itemlist[x].name=(char*)malloc(sizeof(char*));
	itemlist[x].next=(item*)malloc(sizeof(item*));
  }

  item *roomitems = (item *) malloc(5*sizeof(item));
  for (x = 0; x < 6; x++){
        roomitems[x].name=(char*)malloc(sizeof(char*));
        roomitems[x].next=(item*)malloc(sizeof(item*));
  }
  functake(itemlist, nn);
  functake(itemlist,n);
  //funcdrop(itemlist, nn);
  itemscount(itemlist);
}

*/
