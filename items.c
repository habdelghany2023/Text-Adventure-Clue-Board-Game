#include "items.h"
#include "rooms.h"

//Initialize the item struct
struct Item *item(char* name, char *description, struct Item* next){
    struct Item* new_item;
    new_item = (struct Item*) malloc(sizeof(struct Item));
    new_item->name = name;
    new_item->description = description;
    new_item->next = next;
    return new_item;
};

//Will search for an item of a given name in a given list of items and return the item that matches the name.
struct Item* take_item (char *name, struct Item* items){
    struct Item* curr = items;
    struct Item* result = NULL;
    while(curr->next != NULL){
        if (strcmp(curr->next->name, name) == 0){
            result = curr->next;
            curr->next = curr->next->next;
            break;
        }
	if(curr->next == NULL){
            return NULL;
        }
        curr = curr->next;
    }
    return result;
};

//Adds an item to the avatars inventory
struct Item *add_item(struct Item *inputItem, struct Item *items){
    struct Item *current = items;
    if(inputItem == NULL){
	printf("This is an invalid call");
	return items;
    }
    while(current->next != NULL){
	current = current->next;
    }
    current->next = inputItem;
    inputItem->next = NULL;
    return items;
};

//Prints the players inventory
void print_inventory(struct Item *items){
    struct Item *current = items;
    while(current != NULL){
        printf("%s\n", current->name);
        current = current->next;
    }
}

//Prints the items in the current room
void print_room_items(struct Item *items){
    struct Item *current = items;
    if(current == NULL){
	printf("There are no items in the room\n");
	return;
    }
    printf("These are the items in the room: ");
    while(current != NULL){
        printf("%s\n", current->name);
        current = current->next;
    }
}
