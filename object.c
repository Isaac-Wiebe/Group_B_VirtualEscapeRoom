#include <stdio.h>
#include "object.h"

/************************* Object Descriptions *************************/
OBJECT_t objs[] = {
	/***** stages *****/
	{"a bright white room", "stage1", location, confined, NULL, NULL},	// NULL: stages aren't visible and part of any location
	{"a dark yellow room", "stage2", location, confined, NULL, NULL},
	{"a crimson red room", "stage3", location, confined, NULL, NULL},
	/***** The player *****/
	{"yourself", "yourself", actor, regular, NULL, stage1},				// player starts in stage 1
	
	/******************** stage 1 objects ********************/
	/** Table with a letter **/
	{"a wooden table", "table", visible_object, regular,
	"The table seems strudy at first glance\n"
	"You tried to sit down\n"
	"You immediately stand up as it creaks under your weight\n"
	"There is also a letter on the table\n"
	"Some parts of the letter seems to be legible\n"
	"Reading the letter might give you a better idea about its contents\n"", stage1},
	/** A letter **/
	{"a dusty letter", "letter", hidden_object, regular, 
	  "dear ashford,\n"
	"it has been a Long time since i wrote a letter to you. the weather is\n"
	"getting pretty cold right now, enough to freeze my Hand. i bought a\n"
	"cheap sweater for Twelve dollars, and it's better now.\n"
	"the farmers' market is a Short walk from where i live. i remember how\n"
	"i injured my left Hand once while trying to ride a bicycle there. The\n"
	"vendors are preparing their stalls for christmas which is only Seven \n"
	"days away.\n"
	"i really wish you could be here with all of us during the holiday. we..\n"
	"............................\n"
	"The rest of the letter is illegible", stage1},", stage1},
	/** A clock **/
	{"a broken clock", "clock", visible_object, regular, 
	"The clock hands are not moving.\n"
	"You check the battery, only to find that it's long dead\n"
	"The hand for seconds is missing.\n"
	"You might be able to move the hour and minute hand.\n", stage1},
	{"a silver key", "key1", usable_object, regular, NULL, stage1},
	{"a silver door", "door1", visible_object, closed, NULL, stage1},
	/** PuzzleA: uses table, letter, and clock **/
	{"the first puzzle", "puzzle1", puzzle, unsolved, NULL , stage1},
	
	
	/******************** stage 2 objects ********************/
	{"a gold key", "key2", usable_object, regular, NULL, stage2},
	{"a gold door", "door2", visible_object, closed, NULL, stage2},
	{"a jigsaw puzzle", "jigsaw", puzzle, unsolved, NULL, stage2},
	
	/******************** stage 3 objects ********************/
	{"a ruby key", "key3", usable_object, regular, NULL, stage3},
	{"a ruby door", "door3", visible_object, closed, NULL, stage3}
};
