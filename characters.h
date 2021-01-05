#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdio.h>
#include <stdlib.h>
#include "rooms.h"

//Creation of player struct
struct Player{
    char* name;
    struct Item *inventory;
    struct Rooms *room;
};

//Creation of character struct
struct Character{
    char *name;
    char *description;
    struct Character *next;
};

//Initialization of struct Character
struct Player *player (char *name, struct Item *inventory, struct Rooms *room);

//Initialization of struct Character
struct Character *character (char *description, char *name, struct Character *next);

//goal: Moves the character to the room the player is in when clue is called
//param character: Character* representing the character
//param room: Rooms* representing the room
//return: Nothing
void move_character(struct Character *character, struct Rooms *room);

//goal: Prints the characters in the players current room
//param character: Character* representing the head of a *character list
//return: Nothing
void print_character_in_room(struct Character *character);

//goal: Prints the current room the player is in
//param player: Player* representing the player struct
//return: Nothing
void printCurrentRoom(struct Player *player);

//goal: When look is inputted, prints which directions you can go, the characters in the room, and the items in the room based on the players location
//param room: Rooms* representing the room the avatar is in
//param player: Player* representing the avatar
//param i: Integer representing the current row in the room board
//param j: Integer representing the current column in the room board
//return: Nothing
void lookAround(struct Rooms* room, struct Player *player, int i, int j);

//goal: //Will search for a character in the game board and return the character that matches the name inputted by the user
//param name: a char* to the name the user inputted
//param roomArr: a Rooms* representing the game board
//return: a Character* representing the desired character
struct Character *take_char(char*name, struct Rooms *roomArr[3][3]);

//goal: To check if an item in the player's inventory matches the correct item
//param player: Player* representing the avatar
//param correctItem: Item* representing the correct item
//return: true or false depending on if the player's invenotry contains the correct item
bool solvedItem(struct Player *player, struct Item *correctItem);

//goal: To check if an item in the room matches the correct item
//param player: Player* representing the avatar
//param correctItem: Item* representing the correct item
//return: true or false depending on if the room contains the correct item
bool solvedItemRoom(struct Player *player, struct Item *correctItem);

//goal: To check if the character in the room matches the correct character
//param player: Player* representing the avatar
//param correctChar: a Character * representing the correct character
//return: true or false depending on if the inputted character matches the correct character
bool solvedChar(struct Player *player, struct Character *correctChar);

//goal: To check if the room the player is in matches the correct room
//param player: Player* representing the avatar
//param correctRoom: Rooms * representing the correctRoom
//return: true or false depending on if the room the avatar is in is the right one
bool solvedRoom(struct Player *player, struct Rooms *correctRoom);

//goal: Checks to see if the player correctly guessed the murderer, the item, and the room based on the results of 
//solvedItem, solvedItemRoom, solvedChar, and solvedRoom
//param roomTrue: boolean representing the return type of solvedRoom
//param itemTrue: boolean representing the return type of both solvedItem and solvedItemRoom
//param charTrue: boolean representing the return type of solvedChar
//return: true if roomTrue, itemTrue and charTrue are all true, else returns false
bool solvedMurder(bool roomTrue, bool itemTrue, bool charTrue);

#endif // character
