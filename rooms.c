#include "rooms.h"

//Initialize the room struct
struct Rooms *room(char *name, struct Item *items, struct Character *character){
    struct Rooms* new_room;
    new_room = (struct Rooms*)malloc(sizeof(struct Rooms));
    new_room->name = name;
    new_room->items = items;
    new_room->character = character;
    return new_room;

};
