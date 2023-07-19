#include "adventure.h"

static char input[100] = "\n";


//arbitrary answers for testing
static char answers[3][10] = {"1", "Walter", "pipe"};
static char rooms[9][8] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
static char items[6][10] = {"candle", "dagger", "pipe", "gun", "rope", "hammer"};
static char characters[5][10] = {"Walter", "Jessie", "Saul", "Mike", "Gus"};

static Room *currRoom;

//Takes input, and matches it to command being called
//Returns text accouunting for incorrect inputs
bool parser(Room *x,Room *curr, item *y, char *input){ 
   char inp[100];
   strcpy(inp, input);

   //verb is function being called, noun is in case more strings are required in function call
   char *verb = strtok(input, " \n");
   char *noun1 = strtok(NULL, " \n");
  
   if (verb != NULL) {
     // quit to stop running loop
      if (strcasecmp(verb, "quit") == 0) {
         return false;
      }
      //list to see all rooms, characters, and items
      else if (strcasecmp(verb, "list") == 0)
      {
	printf("Rooms: kitchen, ballroom, conservatory, dining, billiards, library, lounge, hall, study\n");
	printf("Items: candle, dagger, pipe, gun, rope, hammer\n");
	printf("Characters: Walter, Jessie, Saul, Mike, Gus\n");
      }
      //help to get table of commands
      else if (strcasecmp(verb, "help") == 0) {
	printf("Table of commands: \n");
	printf("list: check list items, characters and rooms\n");
	printf("look: see which rooms are near, and items and characters in the current room\n");
	printf("go: move to an adjascent room by stating the go + the direction\n");
	printf("take: pick up item from room into inventory\n");
	printf("drop: drop item from inventory into room\n");
	printf("inventory: show your current list of items\n");
	printf("clue: guess who done it and what they used\n");
      }
      else if (strcasecmp(verb, "look") == 0) {
	 lookroom(currRoom);
      }
      else if (strcasecmp(verb, "go") == 0){
	if (noun1  != NULL) {
	  currRoom = funcgo(currRoom,noun1);
	}
	else {
	  printf("Try again, go should be followed by a direction\n");
	  return true;
	}
      }
      else if (strcasecmp(verb, "take") == 0) {
	//take into inventory(y) but drop from room(x->itemlist)
        if (noun1  != NULL) {	  

	  /////////check if item is in the room and can be picked up
	  
         functake(y,noun1);
	
	  // funcdrop(x->itemlist,noun1);
        }
        else {
          printf("Try again, take should be followed by a valid item\n");
	  return true;
	}
      }
      //drop item from an itemlist
      else if (strcasecmp(verb, "drop") == 0)
      {
        // take into room(x->itemlist) but drop from inventory(y)
        if (noun1 != NULL)
        {
          //functake(x->itemlist,noun1);
          funcdrop(y,noun1);
	}
        else {
          printf("Try again, take should be followed by a valid item\n");
	  return true;
	}
      }
      //inventory returns list of of items in avatar's inventory
      else if ((strcasecmp(verb, "inventory")) ==0){
	itemscount(y); 
      }
      //clue to make an attempt at winning the game
      //enter clue item character
      else if ((strcasecmp(verb, "clue")) == 0) {
	return  execClue(inp, y);
      }
      else {
	  printf("I don't know how to '%s'.\n", verb);
      }	
   }
   return true;
}

//returns boolean depending on success of clue guess
/////// count of clue guesses
bool execClue(char string[], item *itemList)
{
    char *command[10] = {NULL};
    int i = 0;

    command[i] = strtok(string, " ");
    while (command[i] != NULL)
        command[++i] = strtok(NULL, " ≈ß");

    // command[0] will be the clue command
    // command[1] will be character
    // command[2] will be item

    // if one of char or item isnt entered
    if (command[1] == NULL || command[2] == NULL)
    {
        printf("incomplete expression - char or item not entered");
        return true;
    }

    char character[10];
    char item[10];
    strcpy(character, command[1]);
    strcpy(item, command[2]);

    strtok(item, " \n");
    char room[] = "1";
    bool charReal = false;
    bool itemReal = false;
    bool itemExists = false;
    bool roomMatch = false;
    bool charMatch = false;
    bool itemMatch = false;

    //checking if char entered exists
    for (int j = 0; j < 5; j++)
    {
        if (strcasecmp(characters[j],character) == 0)
        {
           charReal = true;
        }
    }
    if (!charReal)
    {
        printf("the entered character does not exist");
        return true;
    }

    /////add code for bringing character to the room
    
    // checking if item entered exists
    for (int k = 0; k < 6; k++)
    {
        if (strcasecmp(items[k], item) == 0)
        {
            itemReal = true;
        }
    }
    if (!itemReal)
    {
        printf("the entered item does not exist");
        return true;
    }
    //checking if item in inventory
    int b = 0;
    while(*itemList[b].name != '\0'){
      if(strcasecmp((itemList +b)->name, item) ==0){
	itemExists = true;
      }
      b++;
    }

    ////////check if item in room

    if(!itemExists){
      printf("specified item not in inventory or in room");
      return true;
    }
    if (strcasecmp(answers[0], room) == 0)
    {
        roomMatch = true;
        printf("ROOM MATCH \n");
    }
    else
    {
        printf("ROOM MISMATCH\n");
    }
    if (strcasecmp(answers[1], character) == 0)
    {
        charMatch = true;
        printf("CHARACTER MATCH\n");
    }
    else
    {
        printf("CHARACTER MISMATCH\n");
    }
    if (strcasecmp(answers[2], item) == 0)
    {
        itemMatch = true;
        printf("ITEM MATCH\n");
    }
    else
    {
        printf("ITEM MISMATCH\n");
    }
    if (roomMatch && charMatch && itemMatch)
    {
        printf("SOLVED");
        return false;
    }
    return true;
}

static bool getInput(void) {
   printf("\n--> ");
   return fgets(input, sizeof input, stdin) != NULL;
}
 
void generateAnswer(){
  srand (time(NULL));
  strcpy(answers[0], rooms[rand()%10]);
  strcpy(answers[1], items[rand()%7]);
  strcpy(answers[2], characters[rand()%6]);

  //printf("Room: %s, Item: %s, Char: %s \n", answers[0], answers[1], answers[2]);
  //char* room1 = "locker"
}

int main(){

  int roomSize = sizeof(struct Room);
  Room *rptr = (Room *) malloc(9*roomSize);
  Room *curr = (Room *) malloc(9*roomSize);

  curr = (rptr+5);
  currRoom = curr;
  
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
  
  setName(rptr);
  setRooms(rptr);
  setitems(rptr);
  
  printf("Welcome to the Game.\nType help for commands"); 

  //this is the main loop of the game
  while (parser(rptr,curr,itemlist, input) && getInput());
  printf("\nBye!\n");

  free(rptr);
  return 0;
}

/*
char dir[] = "east";
  setName(rptr);
  setRooms(rptr);
  printboard(rptr);
  shuffle(rptr);
  printf("----------------------\n");
  funcgo(rptr,dir);
  lookroom(rptr);

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
  
  functake(itemlist, n);
  functake(itemlist,nn);
  funcdrop(itemlist, n);
  itemscount(itemlist);
*/
