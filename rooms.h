#ifndef ROOM_H
#define ROOM_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "items.h"
#include "characters.h"

//The creation of struct rooms
struct Rooms{
    char *name;
    struct Item *items;
    struct Character *character;

};

//Initialize the room struct
struct Rooms *room(char *name, struct Item *items, struct Character *character);

#endif // room
