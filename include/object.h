#ifndef __OBJECT_H__
#define __OBJECT_H__



/***** OBJECT Types and States *****/
typedef enum type{
	location = 0,
	visible_object = 1, 
	hidden_object = 2,
	usable_object = 3,
	puzzle = 4,
	actor = 5
} type_t;

typedef enum state{
	closed = 0, open = 1,				// For doors
	confined = 2, unrestricted = 3,		// For stages
	unsolved = 4, solved = 5,			// For puzzles
	hidden = 6, revealed = 7,			// For keys
	regular = 8
} state_t;


/***** OBJECT Structure *****/
typedef struct object{
	const char *description;
	const char *tag;
	type_t type;
	state_t state;
	const char *detailed_description;
	struct object *location;
} OBJECT_t;
extern OBJECT_t objs[];


/***** Object References using symbolic names *****/
/* Stages */
#define stage1 	(objs + 0)
#define stage2 	(objs + 1)
#define stage3 	(objs + 2)
/* Actors */
#define player 	(objs + 3)
/* Objects */
#define table 	(objs + 4)
#define letter	(objs + 5)
#define clock 	(objs + 6)
#define key1 	(objs + 7)
#define door1 	(objs + 8)
#define puzzle1 (objs + 9) // TODO: CHANGED FROM objs + 13
#define sliding_puzzle (objs + 10) // TODO: ADDED THIS
#define puzzle2 (objs + 11) // TODO: CHANGED from objs + 14
#define key2 	(objs + 12) // TODO: CHANGED from objs + 9
#define door2 	(objs + 13) // TODO: Changed from objs + 10
#define key3 	(objs + 14) // TODO: Changed from objs + 11
#define door3 	(objs + 15) // TODO: " " 12
/* End: always update this! */
#define end_of_objs (objs + 16) //TODO: was 15



#endif

