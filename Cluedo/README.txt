
The game should be compiled by the following commands:
    gcc rooms.h
    gcc items.h
    gcc adventure.h
    gcc adventure.c rooms.c items.c

The game will start once compiled followed by this command:
    ./a.out

rooms.h/items.h/adventure.h:
    Header files, which contain struct definitions for Rooms, Items, and Characters.
    Function initializations are also in these files.

rooms.c:
    This file takes care of building the game board, and setting up the struct Room argument pointers.
    
    The game board is built by setrooms, which sets pointers to each direction of the room you are currently in.
    If there is no room to a certain direction, the pointer is set to point to NULL.

    For example; roomptr->West = NULL, (roomptr+1)->South = (roomptr+4)
    The board looks like this:
    1	2   3
    4	5   6
    7	8   9

    To set names of all the boards, the function setName assigns each rooms->name to one of the nine names.
    The file also includes the functions for go(switch to an adjascent room), and look(check which room you are in, rooms adjascent to you, and the items and characters in the room).

items.c:
    Contains functions for take(add item to a linked list of items), drop(remove item from item linked list).
    Also has function, itemlist(prints items in an itemlist. Can be a rooms or avatars).

adventure.c:
    Contains the main function, in which the rooms itemlist, avatars itemlist, Room ptr are created.
    File has main loop which keeps user input open till "quit" is called.
    parser function takes input and directs it to the correct function, and returns text.
    ExecClue function is used for clue attempt, where user can guess who done it.
    	     - Checks for Room, Character, and Item matches.
    generateAnswer function creates a random answer, from list of items, characters and rooms.
    
