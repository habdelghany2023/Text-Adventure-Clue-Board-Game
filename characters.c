#include "characters.h"

//Initialization of struct Player
struct Character *character (char *name, char *description, struct Character *next){
    struct Character *new_character;
    new_character = (struct Character*)malloc(sizeof(struct Character));
    new_character->name = name;
    new_character->description = description;
    new_character->next = next;
    return new_character;

};

//Initialization of struct Character
struct Player *player (char *name, struct Item *inventory, struct Rooms *room){
    struct Player *new_player;
    new_player = (struct Player *)malloc(sizeof(struct Player));
    new_player->name = name;
    new_player->inventory = inventory;
    new_player->room = room;
    return new_player;

};

//Moves the character to the room the player is in when clue is called


void move_character(struct Character *character, struct Rooms *room){
    struct Character *current = room->character;
    while (current->next != NULL){
       current = current -> next;
    }
    current->next = character;
    character->next = NULL;
};

//Will search for a character in the game board and return the character that matches the name inputted by the user
struct Character *take_char(char* name, struct Rooms *roomArr[3][3]){
    struct Character *current;
    struct Character *result;
    for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
	   current = roomArr[i][j]->character;
	   while(current != NULL && current->next != NULL){
		if(strcmp(current->next->name, name) == 0){
		    result = current->next;
		    current->next = current->next->next;
		    break;
		}
		current = current->next;
	   }
	}
    }
    return result;
};

//Prints the characters in the players current room
void print_character_in_room(struct Character *character){
    struct Character *current = character;
    if(current == NULL){
	printf("There are no characters in this room.\n");
	return;
    }
    printf("These are the characters in the room: ");
    while(current != NULL){
        printf("%s\n", current->name);
        current = current->next;
    }
}

//Prints the current room the player is in
void printCurrentRoom(struct Player *player){
    printf("This is the room you are currently in \n");
    printf("%s\n", player->room->name);
}

//When look is inputted, prints which directions you can go, the characters in the room, and the items in the room based on the players location
void lookAround(struct Rooms* room, struct Player *player, int i, int j){
    if(i -1 >= 0){
       printf("You can move north\n");
    }
    if(i + 1<= 2){
        printf("You can move south\n");
    }
    if(j +1 <= 2){
        printf("You can move east\n");
    }
    if(j - 1>= 0){
       printf("You can move west\n");
    }
    print_room_items(player->room->items);
    print_character_in_room(room->character);
    printCurrentRoom(player);
}

//To check if an item in the player's inventory matches the correct item
bool solvedItem(struct Player *player, struct Item *correctItem){
    struct Item *inventoryCurr = player->inventory;
    while(inventoryCurr->next != NULL){
	if(strcmp(correctItem->name, inventoryCurr->next->name) == 0){
            return true;
        }
        inventoryCurr = inventoryCurr->next;
    }
    return false;
}

//To check if an item in the room matches the correct item
bool solvedItemRoom(struct Player *player, struct Item *correctItem){
    struct Item *roomItemCurr = player->room->items;
    while(roomItemCurr->next != NULL){
        if(strcmp(correctItem->name, roomItemCurr->next->name) == 0){
            return true;
           
        }
        roomItemCurr = roomItemCurr->next;
    }
    return false;
}

//To check if the character in the room matches the correct character
bool solvedChar(struct Player *player, struct Character *correctChar){
    struct Character *characterCurr = player->room->character;
    while(characterCurr->next != NULL){
        if((strcmp(correctChar->name, characterCurr->next->name) == 0)){
            return true;
            break;
        }
        characterCurr = characterCurr->next;
    }
    return false;
}

//To check if the room the player is in matches the correct room
bool solvedRoom(struct Player *player, struct Rooms *correctRoom){
   if((strcmp(correctRoom->name, player->room->name) == 0)){
        return true;
    }
    else{
	return false;
    }
}

//Checks to see if the player correctly guessed the murderer, the item, and the room based on the results of 
//solvedItem, solvedItemRoom, solvedChar, and solvedRoom
bool solvedMurder(bool roomTrue, bool itemTrue, bool charTrue){
   if(roomTrue && itemTrue && charTrue){
	return true;
   }
   else{
	return false;
   }

}
