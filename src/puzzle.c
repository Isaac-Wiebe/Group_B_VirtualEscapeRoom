#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "ctype.h"
#include "helper.h"
#include "puzzle.h"
#include "object.h"

/**
 * The first puzzle triggered from the clock
 */
void trigger_puzzle1(){
	printf("\nYou found a clock-puzzle!\n");
	/********** Instructions for puzzle 1 **********/
	instructions:
		printf("\nInstructions:\n"
		"********************************************************************\n"
		"*  c. continue:     continue solving the puzzle                    *\n"
		"*  h. hint:         get a hint about the puzzle (reduced reward)   *\n"
		"*  i. instructions: see instructions for this puzzle               *\n"
		"*  q. quit:         quit solving the puzzle and do something else  *\n"
		"********************************************************************\n");
	/********** Start of the puzzle **********/
	puzzle:
		printf("\nWhat would you like to do? c/h/i/q\n");
		char user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'q'){		// user wants to quit the puzzle
			return;
		} else if (tolower(user_intent) == 'i'){
			goto instructions;
		} else if (tolower(user_intent) == 'h'){
			printf("\n%s\n", clock_hint->detailed_description); 	//show hint for the clock_puzzle
			clock_hint->state = used;
			goto puzzle;
		} else if (tolower(user_intent) == 'c'){
			int hour_hand, minute_hand = 0;
			printf("\nYou try to rotate the clock hands using your fingers.\n"
			"Years of dust seems to have made that impossible.\n"
			"You try the knob at the back.\n"
			"It rotates...\n");
			printf("\nSet hour hand to: ");
			scanf("%d", &hour_hand);
			printf("Set minute hand to: ");
			scanf("%d", &minute_hand);
			fflush(stdin);
			printf("\nYou turned the clock hands using the knobs at the back.\n");
			if (hour_hand>=1 && hour_hand<=12 && minute_hand>=0 && minute_hand<=59){
				if (hour_hand==7 && minute_hand==12){
					clock_puzzle->state = solved;
					printf("Suddenly, the clock starts to tick!\n"
					"There seems to be a different energy source somewhere.\n"
					"But that doesn't seem to be quite enough as the clock stops again.\n"
					"Congrats! You have solved this puzzle!\n");
					check_solved_stage1();		// check if all puzzles have been solved
					return;
				} else {
					printf("But nothing happened!\n");
				}
			} else {
				printf("\nI'm not sure what you're trying to do.\n"
				"You must have never seen a real clock!\n");
			}
			goto puzzle;
		} else {
			printf("It seems you don't want to do anything at all!\n");
		}
}





void trigger_puzzle2()
{
    printf("Do you want to attempt sliding the pieces around? (y/n)");
    char user_intent = fgetc(stdin);
    fflush(stdin);        // flush the input buffer
    if(tolower(user_intent) == 'n'){
        return;
    }
    else
    {


        char puzzle[PUZZLE_LENGTH][PUZZLE_LENGTH] = {
            {'\\', '0', '/'},
            {'.', '|', '.'},
            {'/', '.', '\\'}
            };
        char puzzletwo[PUZZLE_LENGTH][PUZZLE_LENGTH];
        for (int i = 0; i < PUZZLE_LENGTH; i++)
        {
            for (int j = 0; j < PUZZLE_LENGTH; j++)
            {
                if (puzzle[i][j] == '0')
                    puzzletwo[i][j] = '?';
                else
                    puzzletwo[i][j] = puzzle[i][j];
            }
        }

        printf("\n");

        printf("Use the WASD keys to rearrange the puzzle!\n");
        printf("W => up\n");
        printf("A => left\n");
        printf("S => down\n");
        printf("D => right\n");
        printf("Enter 'q' to quit, or reset the puzzle\n");
        printf("Enter 'h' for a hint, but be careful! Your prize will be affected!\n");
        printf("Type in enter to confirm your selection\n");
        printf("The '?' is a free space to slide tiles in\n");
        printf("\n");


        int cursX = 1;
        int cursY = 0;
        int toggle_screen = 0;
        for (int k = 0; k < 100; k++)
        {
            int choice = rand() % 4;

            switch (choice)
            {
                case 0:
                    if (cursY != PUZZLE_LENGTH - 1)
                    {
                        char temp = puzzletwo[cursY + 1][cursX];
                        puzzletwo[cursY + 1][cursX] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursY++;

                    }
                    break;
                case 1:
                    if (cursX != PUZZLE_LENGTH - 1)
                    {
                        char temp = puzzletwo[cursY][cursX + 1];
                        puzzletwo[cursY][cursX + 1] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursX++;

                    }
                    break;
                case 2:
                    if (cursY != 0)
                    {
                        char temp = puzzletwo[cursY - 1][cursX];
                        puzzletwo[cursY - 1][cursX] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursY--;

                    }
                    break;
                case 3:
                    if (cursX != 0)
                    {
                        char temp = puzzletwo[cursY][cursX - 1];
                        puzzletwo[cursY][cursX - 1] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursX--;

                    }
                    break;
                default:
                    break;


            }


        }

        printf("TARGET\n");
        printf("\n");


        for (int i = 0; i < PUZZLE_LENGTH; i++)
        {
            for (int j = 0; j < PUZZLE_LENGTH; j++)
            {
                printf("%c", puzzle[i][j]);

            }
            printf("\n");
        }

        printf("\n");
        printf("\n");
        printf("YOUR PUZZLE\n");
        for (int i = 0; i < PUZZLE_LENGTH; i++)
        {
            for (int j = 0; j < PUZZLE_LENGTH; j++)
            {
                printf("%c", puzzletwo[i][j]);

            }
            printf("\n");
        }


        int done = 0;


        while (!done)
        {
            int flag1 = 1;

            int input_char;
            input_char = fgetc(stdin);


            if (input_char == 119)
            {
                if (cursY != PUZZLE_LENGTH - 1)
                {
                    char temp = puzzletwo[cursY + 1][cursX];
                    puzzletwo[cursY + 1][cursX] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursY++;

                }

            }
            if (input_char == 97)
            {
                if (cursX != PUZZLE_LENGTH - 1)
                {
                    char temp = puzzletwo[cursY][cursX + 1];
                    puzzletwo[cursY][cursX + 1] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursX++;

                }
            }

            if (input_char == 115)
            {
                if (cursY != 0)
                {
                    char temp = puzzletwo[cursY - 1][cursX];
                    puzzletwo[cursY - 1][cursX] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursY--;

                }
            }

            if(input_char == 100)
            {
                if (cursX != 0)
                {
                    char temp = puzzletwo[cursY][cursX - 1];
                    puzzletwo[cursY][cursX - 1] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursX--;

                }
            }

            if (input_char == 113)
            {
                printf("Resetting the puzzle\n");
                fflush(stdin);
                return;
            }

            if (input_char == 104)
            {
            	printf("HINT\n");
            	printf("%s", slider_hint->detailed_description);
            	printf("Press the ENTER key to continue...\n");
            	fflush(stdin);
            	getchar();
            	slider_hint->state = used;
            }


            printf("\n");
            printf("\n");

            if (input_char != 10)
            {
                printf("Use the WASD keys to rearrange the puzzle!\n");
                printf("W => up\n");
                printf("A => left\n");
                printf("S => down\n");
                printf("D => right\n");
                printf("Enter 'q' to quit, or reset the puzzle\n");
                printf("Enter 'h' for a hint, but be careful! Your prize will be affected!\n");
                printf("Type in enter to confirm your selection\n");
                printf("The '?' is a free space\n");
                printf("\n");

                printf("TARGET\n");
                printf("\n");
                for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
                {
                    for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
                    {
                    printf("%c", puzzle[i2][j2]);
                    }
                    printf("\n");
                }
                printf("\n");
                printf("\n");
                printf("YOUR PUZZLE\n");
                for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
                {
                    for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
                    {
                        printf("%c", puzzletwo[i2][j2]);
                    }
                    printf("\n");
                }
            }




            for (int i = 0; i < PUZZLE_LENGTH; i++)
            {
                for (int j = 0; j < PUZZLE_LENGTH; j++)
                {
                    if (puzzletwo[i][j] != puzzle[i][j])
                    {
                        if (!(puzzletwo[i][j] == '?' && puzzle[i][j] == '0'))
                        {
                            flag1 = 0;
                        }
                    }
                }

            }
            if (flag1)
                done = 1;
        }
        printf("TARGET\n");
        printf("\n");
        for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
        {
            for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
            {
                printf("%c", puzzle[i2][j2]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
        printf("YOUR PUZZLE\n");
        for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
        {
            for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
            {
                if (puzzletwo[i2][j2] == '?')
                        puzzletwo[i2][j2] = '0';
                printf("%c", puzzletwo[i2][j2]);
            }
            printf("\n");
        }
        printf("The puzzle has been solved!\n");
        sliding_puzzle->state = solved;
        check_solved_stage1();


        fflush(stdin);        // flush the input buffer
        return;
    }
}

/**
 * The third puzzle which is the paper puzzle
 */
void trigger_puzzle3()
{
    printf("A | B | C");
    printf("_ | _ | _");
    printf("D | E | T");
    printf("_ | _ | _");
    printf("I | O | U");

    printf("\n");

    printf(" \\  N  / ");
    printf(" \\ _ /  ");
    printf("Q | P | F");
    printf("  / _ \\  ");
    printf(" / Y   \\ ");

    printf("With the above information solve this puzzle");

    printf("  |");
    printf(" _|");

    printf("\n");

    printf("  _   ");
    printf("|   |  ");
    printf("| _ |");

    printf("\n");

    printf("  /");
    printf(" /");
    printf("|");
    printf(" \\");
    printf("  \\");

    printf("Please your inputs should be in capital letters");
    printf("To quit press q \n To get a hint press h");

    char user_input = fgetc(stdin);
    char word[3];
    int len_word =0;

    if( user_input == 'q')
    {
        return;
    }else {
        while(len_word < 3)
        {

            if( user_input == 'q')
            {
                return;
            }else if( user_input == 'h')
            {
                printf("\n%s\n",paper_hint->description);
                paper_hint->state = used;
            }else{
                word[len_word++] = user_input;
            }

            user_input = fgetc(stdin);
        }

    }

    if(strcmp(word,"AEF") == 0)
    {
        printf("PASS");
        paper_puzzle->state = solved;
    }else{
        printf("FAIL");
        printf("Please examine object again");

    }

    return;





}

/**
 * The fourth puzzle triggered from the graffiti
 */
void trigger_puzzle4(){
	printf("You look closely at the lines\n"
	"It seems like a lot of effort was put into the carvings\n"
	"The carvings are traceable.\n");

	printf("\nYou found a graffiti-puzzle!\n");
	/********** Instructions for puzzle 4 **********/
	instructions:
		printf("\nInstructions:\n"
		"********************************************************************\n"
		"*  c. continue:     continue solving the puzzle                    *\n"
		"*  k. keypad:       start using the keypad again                   *\n"
		"*  p. pattern:      watch the puzzle pattern again                 *\n"
		"*  h. hint:         get a hint about the puzzle (reduced reward)   *\n"
		"*  i. instructions: see instructions for this puzzle               *\n"
		"*  q. quit:         quit solving the puzzle and do something else  *\n"
		"********************************************************************\n");
	/********** Start of the puzzle **********/
	puzzle:
		printf("\nWhat would you like to do? c/k/p/h/i/q\n");
		char user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'q'){		// user wants to quit the puzzle
			return;
		} else if (tolower(user_intent) == 'i'){
			goto instructions;
		} else if (tolower(user_intent) == 'h'){
			printf("\n%s\n", graffiti_hint->detailed_description); 	//show hint for the graffiti_puzzle
			graffiti_hint->state = used;
			goto puzzle;
		} else if (tolower(user_intent) == 'k'){
			goto keypad;
		} else if (tolower(user_intent) == 'p'){
			goto pattern;
		} else if (tolower(user_intent) == 'c'){
			/***** Watch the pattern *****/
			pattern:
				printf("\nAs you trace your finger through the lines...\n"
				"you start to see some common alignments.\n"
				"You find: \n"
				"\n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"________|________|________|________\n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"________|________|________|________\n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"________|________|________|________\n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"        |        |        |        \n"
				"\n"
				"and\n"
				"\n"
				"        |       \n"
				"        |       \n"
				"        |       \n"
				"________|_______\n"
				"        |       \n"
				"        |       \n"
				"        |       \n"
				"        |       \n"
				"\n"
				"and\n"
				"\n"
				"        |        |        \n"
				"        |        |        \n"
				"        |        |        \n"
				"________|________|________\n"
				"        |        |        \n"
				"        |        |        \n"
				"        |        |        \n"
				"________|________|________\n"
				"        |        |        \n"
				"        |        |        \n"
				"        |        |        \n"
				"        |        |        \n"
				"\n");


				printf("You also find three bright red number slots.\n"
				"\n"
				"[9] [1] [?]\n"
				"\n"
				"The [?] slot is accompanied by a keypad containing single-digit keys\n"
				"you might be able to press the keys and see what happens.\n\n");
			/***** start pressing the keypad *****/
			keypad:
				printf("\nWhich key would you like to press?\n");
				int user_result = 10;	// initialize with an invalid keypad number
				scanf("%d", &user_result);
				fflush(stdin);
				if (user_result == 0
					|| user_result == 1 || user_result == 2 || user_result == 3
					|| user_result == 4 || user_result == 5 || user_result == 6
					|| user_result == 7 || user_result == 8 || user_result == 9){

					printf("\nYou pressed %d.\n", user_result);
					printf("\nThe slots now read:\n"
					"\n"
					"[9] [1] [%d]\n"
					"\n", user_result);

					if (user_result == 4){
						graffiti_puzzle->state = solved;
						printf("Suddenly, all the slots light up!\n"
						"In place of the question mark, you now see a 4.\n"
						"The keypad doesn't respond to your presses anymore.\n"
						"Congrats! You have solved this puzzle!\n");
//						check_solved_stage2();		// check if all puzzles have been solved
						return;
					} else {
						printf("But nothing happened!\n");
					}
				} else {
					printf("\nI'm not sure what you're trying to do.\n"
					"Even elementary kids know what a single-digit number is!\n");
				}
				goto puzzle;
		} else {
			printf("It seems you don't want to do anything at all!\n");
		}
}

void trigger_puzzle5()
{
	printf("This piano is grossly out of tune!\n");
	printf("Do you play it anyways?\n");
	char user_intent = fgetc(stdin);
    fflush(stdin);        // flush the input buffer
    if(tolower(user_intent) == 'n'){
        return;
    }
    else {
    	int done = 0;
    	char * firstVerse = "CGCGCGCEG";
    	char * quit = "q";
    	while (!done) {
    		char noteString[10];
    		printf("What string of notes do you play on the piano? (For simplicity, assume"
    		" that the only valid notes are any combination of (notes may repeat) "
    		"of 'A', 'B', 'C', 'D', 'E', 'F', 'G' \n");
    		printf("Enter h for a hint, but be careful! Your prize will be affected\n");
    		printf("Enter 'q' to quit\n");
    		scanf("%s", noteString);

    		if (strcmp(noteString, firstVerse) == 0) {
    			printf("An amazing first verse, albeit out of tune\n");
    			done = 1;
    		}
    		else if (strcmp(noteString, "q") == 0) {
    			fflush(stdin);
    			return;
    		}
    		else if (strcmp(noteString, "h") == 0) {
    			fflush(stdin);
    			printf("%s", piano_hint->detailed_description);
    			printf("Press the ENTER key to continue\n");
    			getchar();
    		}
    		else {
    			printf("The out of tune piano is ghastly to listen to.\n");
    			printf("This string of notes doesn't sound like a song at all\n");
    			printf("Maybe there is sheet music nearby?\n");
    		}
    	}

    	printf("An internal mechanism clinks around in the piano.\n");
    	printf("However, it stopped! It looks like another combination\n");
    	printf("Of notes is needed. A second verse if you will.\n");
    	printf("\n");

    	done = 0;
    	char * secondVerse = "FDFDFDBDG";
    	while (!done) {
    		char noteString[10];
    		printf("It is time to enter the second verse\n");
    		printf("What string of notes do you play on the piano? (For simplicity, assume"
    		"that the only valid notes are any combination of (notes may repeat) "
    		"of 'A', 'B', 'C', 'D', 'E', 'F', 'G' \n");
    		printf("Enter h for a hint, but be careful! Your prize will be affected\n");
    		printf("Enter 'q' to quit\n");
    		scanf("%s", noteString);

    		if (strcmp(noteString, secondVerse) == 0) {
    			printf("An amazing first verse, albeit out of tune\n");
    			done = 1;
    		}
    		else if (strcmp(noteString, "q") == 0) {
    			fflush(stdin);
    			return;
    		}
    		else if (strcmp(noteString, "h") == 0) {
    			fflush(stdin);
    			printf("%s", piano_hint->detailed_description);
    			printf("Press the ENTER key to continue\n");
    			getchar();
    		}
    		else {
    			printf("The out of tune piano is ghastly to listen to.\n");
    			printf("This string of notes doesn't sound like a song at all\n");
    			printf("Maybe there is sheet music nearby?\n");
    		}
    	}
    	printf("The piano's internal mechanism rotates again\n");
    	printf("It appears you have solved the puzzle!\n");
    	fflush(stdin);        // flush the input buffer
    	piano_puzzle->state = solved;
    	check_solved_stage2();
    }
}

/**
 * @brief This is the puzzle for the riddle
 */
void trigger_puzzle6(){

    printf("I APPEAR 3 TIMES IN SEPTEMBER 2 TIMES IN NOVEMBER 1 TIME IN FEBURARY BUT NEVER IN JULY ");
    printf(" WHAT AM I");

    printf("Please your inputs should be in capital letters");
    printf("To quit press q \n To get a hint press h");

    char user_input = fgetc(stdin);
    char word[1];
    int len_word =0;

    if( user_input == 'q')
    {
        return;
    }else {
        while(len_word < 1)
        {

            if( user_input == 'q')
            {
                return;
            }else if( user_input == 'h')
            {
                printf("\n%s\n",riddle_hint->description);
                riddle_hint->state = used;
            }else{
                word[len_word++] = user_input;
            }

            user_input = fgetc(stdin);
        }

    }

    if(strcmp(word,"E") == 0)
    {
        printf("PASS");
        riddle_puzzle->state = solved;
    }else{
        printf("FAIL");
        printf("Please examine object again");

    }

    return;
}



/**
 * The seventh puzzle triggered from the manual
 */
void trigger_puzzle7(){

	printf("\nYou found a code-puzzle!\n");
	/********** Instructions for puzzle 7 **********/
	instructions:
		printf("\nInstructions:\n"
		"********************************************************************\n"
		"*  c. continue:     continue solving the puzzle                    *\n"
		"*  k. keypad:       start using the keypad of the blue_lock        *\n"
		"*  v. view:         view the clues in the manual again             *\n"
		"*  h. hint:         get a hint about the puzzle (reduced reward)   *\n"
		"*  i. instructions: see instructions for this puzzle               *\n"
		"*  q. quit:         quit solving the puzzle and do something else  *\n"
		"********************************************************************\n");
	/********** Start of the puzzle **********/
	puzzle:
		printf("\nWhat would you like to do? c/k/v/h/i/q\n");
		char user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'q'){		// user wants to quit the puzzle
			return;
		} else if (tolower(user_intent) == 'i'){
			goto instructions;
		} else if (tolower(user_intent) == 'h'){
			printf("\n%s\n", code_hint->detailed_description); 	//show hint for the graffiti_puzzle
			code_hint->state = used;
			goto puzzle;
		} else if (tolower(user_intent) == 'k'){
			goto keypad;
		} else if (tolower(user_intent) == 'v'){
			goto clues;
		} else if (tolower(user_intent) == 'c'){
			printf("\n... ... ...\n"
			"\nFinally, you find five sentences that seems to relate to a hidden code.\n");
		/***** View the relevant clues *****/
			clues:
				printf("\nYou carefully explore the relevant pages...\n\n"
				"manual page 47\n"
				"---------------\n"
				"[7] [8] [2]\n"
				"clue: one number is correct\n"
				"and well placed.\n\n");

				printf("manual page 132\n"
				"---------------\n"
				"[7] [0] [4]\n"
				"clue: one number is correct\n"
				"but wrongly placed.\n\n");

				printf("manual page 139\n"
				"---------------\n"
				"[4] [8] [3]\n"
				"clue: nothing is correct.\n\n");

				printf("manual page 241\n"
				"---------------\n"
				"[2] [1] [7]\n"
				"clue: two numbers are correct\n"
				"but wrongly placed.\n\n");

				printf("manual page 438\n"
				"---------------\n"
				"[4] [8] [1]\n"
				"clue: one number is correct\n"
				"but wrongly placed.\n\n");

				printf("With these hints you might be able to figure out\n"
				"the code of the blue_lock!\n");
				goto puzzle;

			keypad:
				printf("\nYou check the keypad of the blue_lock.\n"
				"it seems you will need a 3-digit key to open it.\n");

				printf("\nWhich keys would you like to press?\n");
					int user_result = 0;		// initialize with an invalid keypad number
					scanf("%d", &user_result);
					fflush(stdin);
					if (user_result >= 100 && user_result <= 999){
						printf("\nYou entered [%d].\n", user_result);

						if (user_result == 371){
							code_puzzle->state = solved;
							blue_lock->state = open;
							printf("You hear a mechanized sound!\n"
							"The blue_lock unlocks in front of your eyes.\n"
							"The keypad doesn't respond to your presses anymore.\n"
							"Congrats! You have found the hidden code and solved this puzzle!\n");
	//						check_solved_stage3();		// check if all puzzles have been solved
							return;
						} else {
							printf("But nothing happened!\n");
						}
					} else {
						printf("\nI'm not sure what you're trying to do.\n"
						"You should go back to school and learn about three-digit numbers first!\n");
					}
					goto puzzle;
		} else {
			printf("It seems you don't want to do anything at all!\n");
		}
}



