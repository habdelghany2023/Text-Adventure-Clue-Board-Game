#include "characters.h"
#include "items.h"
#include "rooms.h"
#include "time.h"

//returns an index of the board
void returnArrLocation(int a[2], int r){
    if(r ==1){
        a[0] = 0;
        a[1] = 0;
    }
    if(r == 2){
        a[0] = 0;
        a[1] = 1;
    }
    if(r == 3){
        a[0] = 0;
        a[1] = 2;
    }
    if(r == 4){
        a[0] = 1;
        a[1] = 0;
    }
    if(r == 5){
        a[0] = 1;
        a[1] = 1;
    }
    if(r == 6){
        a[0] = 1;
        a[1] = 2;
    }
    if(r == 7){
        a[0] = 2;
        a[1] = 0;
    }
    if(r == 8){
        a[0] = 2;
        a[1] = 1;
    }
    if(r == 9){
       a[0] = 2;
       a[1] = 2;
    }
}

//swaps the items at the given index
void swapItems(int i, int j, struct Item *itemArr[9]){
    struct Item *temp = itemArr[i];
    itemArr[i] = itemArr[j];
    itemArr[j] = temp;
}

//swaps the characters at the given index
void swapCharacters(int i, int j, struct Character *charArr[9]){
    struct Character *temp = charArr[i];
    charArr[i] = charArr[j];
    charArr[j] = temp;
}

//swaps the rooms at the given index
void swapRoom(int a, int b, int i, int j, struct Rooms *roomsArr[3][3]){
    struct Rooms *temp = roomsArr[i][j];
    roomsArr[i][j] = roomsArr[a][b];
    roomsArr[a][b] = temp;
    
}

//randomizes the rooms
void randomizeRooms(struct Rooms *roomArr[3][3], int a[2], int sizeOfRoomArr){
    srand(time(NULL));
    int randomNumber;
    for(int i = 2; i > 0; i--){
        for(int j = 2; j > 0; j--){
            randomNumber = rand() % sizeOfRoomArr;
            returnArrLocation(a, randomNumber);
            swapRoom(a[0], a[1], i, j, roomArr);
            sizeOfRoomArr--;

        }
    }

} 

//randomizes the items
void randomizeItems(struct Item *itemsArr[9], int sizeOfItems){
    srand(time(NULL));
    for(int i = 8; i > 0; i--){
        int j = rand()% sizeOfItems;
	swapItems(i, j, itemsArr);
	sizeOfItems--;
    }

}

//randomizes the characters
void randomizeCharacters(struct Character *characterArr[9], int sizeOfCharacter){
    srand(time(NULL));
    for(int i = 8; i >= 0; i--){
        int j = rand() % sizeOfCharacter;
        swapCharacters(i, j, characterArr);
	sizeOfCharacter--;
    }

}

//links the rooms item list to the item at the specified index
void linkItemstoRooms(struct Rooms *roomArr[3][3], struct Item *itemsArr[9]){
    int itemIndex = 0;
    for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
	    roomArr[i][j]->items = itemsArr[itemIndex];
	    itemIndex++;
	}
    }
}

//links the rooms character list to the character at the specified index
void linkCharacterstoRooms(struct Rooms*roomArr[3][3], struct Character *charArr[9]){
    int charIndex = 0;
    for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
	    roomArr[i][j]->character = charArr[charIndex];
	    charIndex++;
	}
    }
}

//Prints the controls of the game
void printControls(){
    printf("The controls to navigating you avatar are simple: \n");
    printf("If you would like to see your surroundings, type (look)\n");
    printf("If you would like to see all the characters, items, and rooms type (list)\n");
    printf("If you would like to move from room to room type(go DIRECTION) \n");
    printf("If you would like to see your current inventory, type(inventory)\n");
    printf("If you would like to add an item to your inventory, type(add ITEM)\n");
    printf("If you would like to drop an item from your inventory, type(drop ITEM)\n");
    printf("If you would like to try and solve the murder, type(clue CHARACTER)\n");
    printf("Finally if you would like to see this menu again, type(help)\n");

}

//Prints all the characters, items, and rooms in the game
void list(){
    printf("These are the all the items characters and rooms in the game:\n");
    printf("Gun, Knife, Candlestick, Baseball Bat, rope, Wrench\n");
    printf("Mrs. White, Mrs. Green, Colonel Mustard, Professor Plum, Mrs. Peacock\n");
    printf("Kitchen, Bathroom, Master Bedroom, Gaming room, Living room, Dining Room, Office, Guest Bedroom, Guest Bathroom\n");
}

int main(int argc, char*argv[])
{   

    srand(time(NULL));
    int a[2];
    int randomNumber;
    int sizeOfItems = 9;
    int sizeOfCharacters = 9;
    int sizeOfRoomArr = 9;
    bool itemTrue = false;
    bool roomTrue = false;
    bool charTrue = false;
    bool allTrue = false;
    char detectiveName[20];
    int i;
    int j;
    int count = 0;
    char inputArr[30];
    int clueCounter = 0;
    int randomItem = rand() % 6;
    int randomChar = rand() % 5;
    int randomRoom = rand() % 3;
    int randRoom2 = rand() % 3;

    //initializes the items in the game
    struct Item *gun = item("", "", item( "Gun", "a silver gun", NULL));
    struct Item *knife = item("", "", item("Knife", "a sharp knife", NULL));
    struct Item *candleStick = item("", "", item("Candlestick", "a long candle stick", NULL));
    struct Item *baseballBat = item("", "", item("Baseball Bat", "a wooden baseball bat", NULL));
    struct Item *rope = item("","",item("rope", "a small rope", NULL));
    struct Item *wrench = item("", "", item("Wrench", "a gold wrentch", NULL));

    //initializes the dummy items so not every room has an item
    struct Item *dummyItem1 = item("", "", NULL);
    struct Item *dummyItem2 = item("", "", NULL);
    struct Item *dummyItem3 = item("", "", NULL);

    //initializes the characters in the game
    struct Character *mrsWhite = character("", "", character("Mrs. White", "a rich middle-aged lady dressed in white", NULL));
    struct Character *mrsGreen = character("", "", character("Mrs. Green", "a young women who loves the color green", NULL));
    struct Character *mrsPeacock = character("", "", character("Mrs. Peacock", "an old lady who loves peacocks", NULL));
    struct Character *colonelMustard = character("", "", character("Colonel Mustard", "a high ranking officer in the US military", NULL));
    struct Character *profPlum = character("", "", character("Professor Plum", "a professor who specializes in plum agriculture", NULL));
    
    //initializes the dummy characters so not every room includes an item
    struct Character *dummyChar1 = character("", "", NULL);
    struct Character *dummyChar2 = character("", "", NULL);
    struct Character *dummyChar3 = character("", "", NULL);
    struct Character *dummyChar4 = character("", "", NULL);
    
    //initializes the rooms in the game
    struct Rooms *kitchen = room("Kitchen", NULL, NULL);
    struct Rooms *bathroom = room("Bathroom", NULL, NULL);
    struct Rooms *masterBedroom = room("Master Bedroom", NULL, NULL);
    struct Rooms *gamingRoom = room("Gaming Room", NULL, NULL);
    struct Rooms *livingRoom = room("Living Room", NULL, NULL);
    struct Rooms *diningRoom = room("Dining Room", NULL, NULL);
    struct Rooms *office = room("Office", NULL, NULL);
    struct Rooms *guestBedroom = room("Guest Bedroom", NULL, NULL);
    struct Rooms *guestBathroom = room("Guest Bathroom", NULL, NULL);

    //initialize the avatar of the game
    struct Player *avatar = player("", item("","",NULL), NULL);

    //initializes arrays of items, characters, and rooms for randomization and traversal
    struct Item *itemsArr[6] = {gun, knife, candleStick, baseballBat, rope, wrench};
    struct Item *itemArrNull[9] = {gun, knife, candleStick, baseballBat, rope, wrench, dummyItem1, dummyItem2, dummyItem3};
    struct Character *charArr[5] = {mrsWhite, mrsGreen, mrsPeacock, colonelMustard, profPlum};
    struct Character *charArrNull[9] = {mrsWhite, mrsGreen, mrsPeacock, colonelMustard, profPlum, dummyChar1, dummyChar2, dummyChar3, dummyChar4};
    struct Rooms *roomArr[3][3] = {kitchen, bathroom, masterBedroom, gamingRoom, livingRoom, diningRoom, office, guestBedroom, guestBathroom};

    //Decides the correct item, character, and room
    struct Item *correctItem = itemsArr[randomItem]->next;
    struct Rooms *correctRoom = roomArr[randomRoom][randRoom2];
    struct Character *correctChar = charArr[randomChar]->next;

    //randomizes the game board
    randomizeRooms(roomArr, a, sizeOfRoomArr);
    randomizeCharacters(charArrNull, sizeOfCharacters);
    randomizeItems(itemArrNull, sizeOfItems);

    //links up the game so there are items and characters in every room
    linkItemstoRooms(roomArr, itemArrNull);
    linkCharacterstoRooms(roomArr, charArrNull);

    //Prints the start of the game
    printf("Hello dectective! I am so glad you were able to come on such short notice. Mr.Brown has been murdered in the Riverswood Estate.\n");
    printf("Your mission, if you chose to accept it, is to expose the person who commited the murder and bring him to justice!\n");

    printf("Oops I almost forgot, what is you name detective? ");
    
    scanf("%s", detectiveName);
    avatar->name = detectiveName;

    printf("\nOf course! I should have known your name was %s\n", avatar->name);

    printControls();
    printf("\nGood luck Detective!!!!!!\n");

    //Only for demostration purposes
    printf("\nTHIS IS THE CORRECT ITEM: %s\n", correctItem->name);
    printf("THIS IS THE CORRECT ROOM %s\n", correctRoom->name);
    printf("THIS IS CORRECT CHARACTER: %s\n", correctChar->name);
     
    while(clueCounter < 10){

        //randomizes the starting location of the avatar
	if(count == 0){
	    i = rand() % 3;
	    j = rand() % 3;
    	    avatar->room = roomArr[i][j];
	    
	}
	else{
	    printf("\nWhat would you like to do? ");
	}

	//gets user input
	fgets(inputArr, 30, stdin);

	//Checks to see if list was inputed
	if(strncmp(inputArr, "list", 4) == 0){
	    list();
	}
	//Checks to see if INVENTORY was called
        else if(strncmp(inputArr, "inventory", 9) == 0){
            print_inventory(avatar->inventory);
        }
	//Checks to see if help was inputed
	else if(strncmp(inputArr, "help", 4) == 0){
	    printControls();
	}
	//Checks to see if look was inputed
	else if(strncmp(inputArr, "look", 4) == 0){
	    lookAround(avatar->room, avatar, i , j);
	}
        
	//Checks to see if go DIRECTION was inputed
	else if(strncmp(inputArr, "go north", 8) == 0){
	    //Checks to make sure you can't go out of bounds
	    if(i -1 < 0){
		printf("You can't go there! Please try again");
		avatar->room = roomArr[i][j];
	    }
	    else{
		i = i-1;
		avatar->room = roomArr[i][j];
	    }
	}
	else if(strncmp(inputArr, "go south", 8) == 0){
	    //Checks to make sure you can't go out of bounds
	    if(i+1 > 2){
	        printf("You can't go there! Please try again.");
		avatar->room = roomArr[i][j];
	    }
	    else{
		i = i+1;
		avatar->room = roomArr[i][j];
	    }
	}
	else if(strncmp(inputArr, "go west", 7) == 0){
	    //Checks to make sure you can't go out of bounds
	    if(j-1 < 0){
		printf("You can't go there! Please try again");
		avatar->room = roomArr[i][j];
	    }
	    else{
		j = j-1;
		avatar->room = roomArr[i][j];
	    }
	}
	else if(strncmp(inputArr, "go east", 7) == 0){
	    //Checks to make sure you can't go out of bounds
	    if(j + 1 > 2){
		printf("You can't go there! Please try again");
		avatar->room = roomArr[i][j];
	    }
	    else{
	        j = j+1;
		avatar->room = roomArr[i][j];
	    }
	}
	
        //Checks to see if add ITEM was inputted
	else if(strncmp(inputArr, "add Gun", 7) == 0){
	   struct Item *result = take_item("Gun", avatar->room->items);
	   add_item(result, avatar->inventory);
	}
	else if(strncmp(inputArr, "add Knife", 9) == 0){
           struct Item *result = take_item("Knife", avatar->room->items);
           add_item(result, avatar->inventory);
        }
	else if(strncmp(inputArr, "add Candlestick", 15) == 0){
           struct Item *result = take_item("Candlestick", avatar->room->items);
           add_item(result, avatar->inventory);
        }
	else if(strncmp(inputArr, "add Baseball Bat", 16) == 0){
           struct Item *result = take_item("Baseball Bat", avatar->room->items);
           add_item(result, avatar->inventory);
        }
	else if(strncmp(inputArr, "add rope", 8) == 0){
           struct Item *result = take_item("rope", avatar->room->items);
           add_item(result, avatar->inventory);
        }
	else if(strncmp(inputArr, "add Wrench", 10) == 0){
           struct Item *result = take_item("Wrench", avatar->room->items);
           add_item(result, avatar->inventory);
        }

	//Checks to see if drop ITEM was inputted
	else if(strncmp(inputArr, "drop Gun", 8) == 0){
	    struct Item *result = take_item("Gun", avatar->inventory);
	    add_item(result, avatar->room->items);
	}
	else if(strncmp(inputArr, "drop Knife", 10) == 0){
	    struct Item *result = take_item("Knife", avatar->inventory);
	    add_item(result, avatar->room->items);
	}
	else if(strncmp(inputArr, "drop Candlestick", 16) == 0){
	    struct Item *result = take_item("Candlestick", avatar->inventory);
	    add_item(result, avatar->room->items);
	}
	else if(strncmp(inputArr, "drop Baseball Bat", 17) == 0){
	    struct Item *result = take_item("Baseball Bat", avatar->inventory);
	    add_item(result, avatar->room->items);
	}
	else if(strncmp(inputArr, "drop rope", 9) == 0){
	    struct Item *result = take_item("rope", avatar->inventory);
            add_item(result, avatar->room->items);
 	}
	else if(strncmp(inputArr, "drop Wrench", 11) == 0){
	    struct Item *result = take_item("Wrench", avatar->inventory);
            add_item(result, avatar->room->items);
	}

	//Checks to see if clue CHARACTER was inputed
	else if(strncmp(inputArr, "clue Colonel Mustard", 20) == 0){
	    struct Character *result = take_char("Colonel Mustard", roomArr);
	    move_character(result, avatar->room);

	    //Checks if item, room, and character match with the correct item, room, and character
	    itemTrue = solvedItem(avatar, correctItem) || solvedItemRoom(avatar, correctItem);
	    charTrue = solvedChar(avatar, correctChar);
	    roomTrue = solvedRoom(avatar, correctRoom);

	    //Checks to see if the user solved the murder
	    allTrue = solvedMurder(roomTrue, itemTrue, charTrue);
	    if(allTrue == true){
		break;
	    }
	    else{
		if(itemTrue == true){
		    printf("Item Match\n");
		}
		if(roomTrue == true){
		    printf("Room Match\n");
		}
		if(charTrue == true){
		    printf("Character match\n");
		}

		//reset boolean variables
		roomTrue = false;
		itemTrue = false;
		charTrue = false;

		//increments clue counter
		clueCounter++;
	    }
	}
	else if(strncmp(inputArr, "clue Mrs. White", 15) == 0){
	    struct Character *result = take_char("Mrs. White", roomArr);
	    move_character(result, avatar->room);

	    //Checks if item, room, and character match with the correct item, room, and character
	    itemTrue = solvedItem(avatar, correctItem) || solvedItemRoom(avatar, correctItem);
	    charTrue = solvedChar(avatar, correctChar);
            roomTrue = solvedRoom(avatar, correctRoom);

	    //Checks to see if the user solved the murder
            allTrue = solvedMurder(roomTrue, itemTrue, charTrue);

            if(allTrue == true){
                break;
            }
            else{
                if(itemTrue == true){
                    printf("Item Match\n");
                }
                if(roomTrue == true){
                    printf("Room Match\n");
                }
                if(charTrue == true){
                    printf("Character match\n");
                }

		//reset boolean variables
                roomTrue = false;
                itemTrue = false;
                charTrue = false;

		//increments clue counter
		clueCounter++;
            }
	}
	else if(strncmp(inputArr, "clue Mrs. Green", 15) == 0){
	    struct Character *result = take_char("Mrs. Green", roomArr);
	    
	    //Checks if item, room, and character match with the correct item, room, and character
	    move_character(result, avatar->room);
	    itemTrue = solvedItem(avatar, correctItem) || solvedItemRoom(avatar, correctItem);
            charTrue = solvedChar(avatar, correctChar);
            roomTrue = solvedRoom(avatar, correctRoom);

	    //Checks to see if the user solved the murder
            allTrue = solvedMurder(roomTrue, itemTrue, charTrue);

            if(allTrue == true){
                break;
            }
            else{
                if(itemTrue == true){
                    printf("Item Match\n");
                }
                if(roomTrue == true){
                    printf("Room Match\n");
                }
                if(charTrue == true){
                    printf("Character match\n");
                }

		//reset boolean variables
                roomTrue = false;
                itemTrue = false;
                charTrue = false;

		//increments clue counter
		clueCounter++;
            }
	}
	else if(strncmp(inputArr, "clue Mrs. Peacock", 17) == 0){
	    struct Character *result = take_char("Mrs. Peacock", roomArr);
	    move_character(result, avatar->room);

	    //Checks if item, room, and character match with the correct item, room, and character
	    itemTrue = solvedItem(avatar, correctItem) || solvedItemRoom(avatar, correctItem);
            charTrue = solvedChar(avatar, correctChar);
            roomTrue = solvedRoom(avatar, correctRoom);

	    //Checks to see if the user solved the murder
            allTrue = solvedMurder(roomTrue, itemTrue, charTrue);
        
            if(allTrue == true){
                break;
            }
            else{
                if(itemTrue == true){
                    printf("Item Match\n");
                }
                if(roomTrue == true){
                    printf("Room Match\n");
                }
                if(charTrue == true){
                    printf("Character match\n");
                }

		//resets boolean variables
                roomTrue = false;
                itemTrue = false;
                charTrue = false;

		//increments clue counter
		clueCounter++;
            }
	}
	else if(strncmp(inputArr, "clue Professor Plum", 19) == 0){
	    struct Character *result = take_char("Professor Plum", roomArr);
	    move_character(result, avatar->room);

	    //Checks if item, room, and character match with the correct item, room, and character
	    itemTrue = solvedItem(avatar, correctItem) || solvedItemRoom(avatar, correctItem);
            charTrue = solvedChar(avatar, correctChar);
            roomTrue = solvedRoom(avatar, correctRoom);

	    //Checks to see if the user solved the murder
            allTrue = solvedMurder(roomTrue, itemTrue, charTrue);

            if(allTrue == true){
                break;
            }
            else{
                if(itemTrue == true){
                    printf("Item Match\n");
                }
                if(roomTrue == true){
                    printf("Room Match\n");
                } 
                if(charTrue == true){
                    printf("Character match\n");
                }

		//resets boolean variables
                roomTrue = false;
                itemTrue = false;
                charTrue = false;
		
		//increments clue counter
		clueCounter++;
            }
	}

	//Checks to see if the command inputed is a valid command
	else{
	    if(count > 0){
		printf("This was not a valid input please try again.");
	    }
	    count++;
	}
    }
    //Checks to see if you called clue 10 times
    if(clueCounter == 10){
	printf("\nUnfortunetly you were unable to solve the murder, so you are fired from this case!\n");
    }
    //If not you wim the game
    else{
	printf("\nCongrats Detective! You have solved the case! Once again you have proven how amazing you are well done!\n");
    }
   
    //Frees the items
    free(gun);
    free(knife);
    free(candleStick);
    free(baseballBat);
    free(rope);
    free(wrench);
    free(dummyItem1);
    free(dummyItem2);
    free(dummyItem3);

    //Frees the characters
    free(mrsWhite);
    free(mrsGreen);
    free(mrsPeacock);
    free(colonelMustard);
    free(profPlum);
    free(dummyChar1);
    free(dummyChar2);
    free(dummyChar3);
    free(dummyChar4);

    //Frees the rooms
    free(kitchen);
    free(bathroom);
    free(masterBedroom);
    free(gamingRoom);
    free(livingRoom);
    free(diningRoom);
    free(office);
    free(guestBedroom);
    free(guestBathroom);

    //Frees the player
    free(avatar);
    return 0;
}
