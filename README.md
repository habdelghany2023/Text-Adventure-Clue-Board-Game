# Text-Adventure-Clue-Board-Game
For the implementation of the board game clue, I defined all the required structs and arrays in main. From there I randomized the rooms, items, and characters. 
Afterwards, I linked the items and characters to their respective rooms. Everything after (up until the while loop) helps set up the game as well as provide a little context 
behind the adventure that the user is about to partake in. 

After the set up, a while loop continues the game until the user has solved the murder or called the clue command 10 
times. The first if-statement checks to see if it is the start of the game. If it is, the program will randomize the starting point of the player on the game board. If it
is not the start of the game, the program will prompt you with the statement "What would you like to do?". The first if-statement checks to see if the user inputted the
command "list", the second if-statement checks to see if the user inputted the command "help", and the third if-statement checks to see if the user inputted the command "look". 
The next if-statement checks to see if the user inputted the command "inventory".

The following if-statements check to see if go DIRECTION is called. If this is true, the following sub if checks to see if the user inputted a direction that goes beyond the game 
board. If this is the case, the program will reprompt the user to input a valid direction. 

The next set of if-statements checks to see the user inputted add ITEM. If it is true, it will store the result of take_item and add it to the players inventory list. 

The following block of if-statements check to see if the user inputted drop ITEM. If this is the case, it will store the result of take_item and add it to the list of items in theroom.
 
The final block of if-statements check to see if the user inputted clue CHARACTER. If they did, the program will store the result of take_char and move that character to the room
the player is currently in. From there, the program checks to see if the user has the correct item, room, and character. If this is true it will break out the while loop
signifying that the user has solved the case. If only some of what the user inputted is correct, it will print Item Match, Room Match, and Character Match accordingly and
the user will continue playing the game. 

Outside of the while loop, there is an if-statement that checks to see if the clue counter reached 10; if it is true the program will print that the user lost. If this is not the case it will print that the user solved the case. The final set of statements free all the structs that were created in
main.
  

Important Methods:

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

//goal: //Will search for a character in the game board and return the character that matches the name inputted by the user
//param name: a char* to the name the user inputted
//param roomArr: a Rooms* representing the game board
//return: a Character* representing the desired character
struct Character *take_char(char*name, struct Rooms *roomArr[3][3]);

//goal: Moves the character to the room the player is in when clue is called
//param character: Character* representing the character
//param room: Rooms* representing the room
//return: Nothing
void move_character(struct Character *character, struct Rooms *room);

//goal: When look is inputted, prints which directions you can go, the characters in the room, and the items in the room based on the players location
//param room: Rooms* representing the room the avatar is in
//param player: Player* representing the avatar
//param i: Integer representing the current row in the room board
//param j: Integer representing the current column in the room board
//return: Nothing
void lookAround(struct Rooms* room, struct Player *player, int i, int j);

//goal: Checks to see if the player correctly guessed the murderer, the item, and the room based on the results of 
//solvedItem, solvedItemRoom, solvedChar, and solvedRoom
//param roomTrue: boolean representing the return type of solvedRoom
//param itemTrue: boolean representing the return type of both solvedItem and solvedItemRoom
//param charTrue: boolean representing the return type of solvedChar
//return: true if roomTrue, itemTrue and charTrue are all true, else returns false
bool solvedMurder(bool roomTrue, bool itemTrue, bool charTrue);

//randomizes the rooms
void randomizeRooms(struct Rooms *roomArr[3][3], int a[2], int sizeOfRoomArr);

//randomizes the items
void randomizeItems(struct Item *itemsArr[9], int sizeOfItems);

//randomizes the characters
void randomizeCharacters(struct Character *characterArr[9], int sizeOfCharacter);


Link to video demostration:
https://www.youtube.com/watch?v=hY00Z4s4AMQ
