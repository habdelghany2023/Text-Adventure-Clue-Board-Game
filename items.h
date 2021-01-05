#ifndef ITEMS_H
#define ITEMS_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//Defines struct
struct Item{
    char *name;
    char *description;
    struct Item *next;

};

//Initialize the item struct
struct Item *item(char* name, char *description, struct Item* next);

//goal: Will search for an item of a in a given list of items and return the item that matches the name.
//param name: a char* pointer to the name inputted by the user
//param items: a Item * representing the head of the items list
//return: an Item * representing the item inputted by the user 
struct Item* take_item (char *name, struct Item* items);

//goal: Adds an item to the players inventory
//param inputItem: an Item * representing the pointer that take_item returns
//param items: an Item * representing the head of the players inventory list
//return: an Item * to the head of the players inventory list 
struct Item *add_item(struct Item *inputItem, struct Item *items);

//goal: Prints the players inventory
//param items: an Item * to the head of the players inventory list
void print_inventory(struct Item *items);

//goal: Prints the items in the current room
//param items: an Item * to the head of the list of items in the current room
//return: Nothing
void print_room_items(struct Item *items);
#endif // items
