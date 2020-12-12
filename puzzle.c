#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include "object.h"
#include "ctype.h"

/**
 * The first puzzle triggered from the clock
 */
void trigger_puzzle1(){
	printf("Do you want to manually set the time? y/n\n");
	char user_intent = fgetc(stdin);
	fflush(stdin);		// flush the input buffer
	
	if(tolower(user_intent) == 'n'){
		return;
	} else if (tolower(user_intent) == 'y'){
		do {
			int hour_hand, minute_hand = 0;
			printf("\nSet hour hand to: ");
			scanf("%d", &hour_hand);
			printf("Set minute hand to: ");
			scanf("%d", &minute_hand);
			fflush(stdin);
			if (hour_hand>=1 && hour_hand<=12 && minute_hand>=0 && minute_hand<=59){
//				printf("\nThe time is now  %d:%d\n", hour_hand, minute_hand);
				if (hour_hand==7 && minute_hand==12){
					puzzle1->state = solved;
					printf("Suddenly, the clock starts to tick!\n"
					"There seems to be a different energy source somewhere.\n"
					"But that doesn't seem to be quite enough as the clock stops again.\n"
					"Congrats! You have solved this puzzle!\n\n");
					return;
				} else {
					printf("Nothing else happened!\n\n");
				}
			} else {
				printf("\nI'm not sure what you're trying to do.\n"
				"You must have never seen a real clock!\n\n");
			}
			printf("Do you want to try again? y/n\n");
			user_intent = fgetc(stdin);
			fflush(stdin);
		} while(tolower(user_intent) == 'y');
	} else {
		printf("It seems you want to do neither!\n");
	}

void trigger_puzzle2() 
{

	char puzzle[PUZZLE_LENGTH][PUZZLE_LENGTH] = {
		{'\\', '0', '/'},
		{'.', '|', '.'},
		{'/', '.', '\\'}
		};
	char puzzle2[PUZZLE_LENGTH][PUZZLE_LENGTH];
	for (int i = 0; i < PUZZLE_LENGTH; i++)
	{
		for (int j = 0; j < PUZZLE_LENGTH; j++)
		{
			if (puzzle[i][j] == '0')
				puzzle2[i][j] = '?';
			else
				puzzle2[i][j] = puzzle[i][j];
		}
	}
	
	printf("\n");
	
	printf("Use the WASD keys to rearrange the puzzle!\n");
	printf("W => up\n");
	printf("A => left\n");
	printf("S => down\n");
	printf("D => right\n");
	printf("Type in enter to confirm your selection\n");
	printf("The '?' is a free space to slide tiles in\n");
	printf("\n");
	
	
	int cursX = 1;
	int cursY = 0;
	for (int k = 0; k < 1000; k++)
	{
		int choice = rand() % 4;
		
		switch (choice)
		{
			case 0:
				if (cursY != PUZZLE_LENGTH - 1)
				{
					char temp = puzzle2[cursY + 1][cursX];
					puzzle2[cursY + 1][cursX] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursY++;
				
				}
				break;
			case 1:
				if (cursX != PUZZLE_LENGTH - 1)
				{
					char temp = puzzle2[cursY][cursX + 1];
					puzzle2[cursY][cursX + 1] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursX++;
				
				}
				break;
			case 2:
				if (cursY != 0)
				{
					char temp = puzzle2[cursY - 1][cursX];
					puzzle2[cursY - 1][cursX] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursY--;
					
				}
				break;
			case 3:
				if (cursX != 0)
				{
					char temp = puzzle2[cursY][cursX - 1];
					puzzle2[cursY][cursX - 1] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
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
			printf("%c", puzzle2[i][j]);
				
		}
		printf("\n");
	}
	
	
	int done = 0; 
	
	
	while (!done)
	{
		int flag1 = 1;	
		
		char buf[1];
		read(1, &buf, sizeof(buf));
		int input_char = buf[0];
		
		if (input_char == 119)
		{
			if (cursY != PUZZLE_LENGTH - 1)
			{
				char temp = puzzle2[cursY + 1][cursX];
				puzzle2[cursY + 1][cursX] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursY++;
				
			}
		
		}
		if (input_char == 97)
		{
			if (cursX != PUZZLE_LENGTH - 1)
			{
				char temp = puzzle2[cursY][cursX + 1];
				puzzle2[cursY][cursX + 1] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursX++;
				
			}
		}
		
		if (input_char == 115)
		{
			if (cursY != 0)
			{
				char temp = puzzle2[cursY - 1][cursX];
				puzzle2[cursY - 1][cursX] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursY--;
				
			}
		}
		
		if(input_char == 100)
		{
			if (cursX != 0)
			{
				char temp = puzzle2[cursY][cursX - 1];
				puzzle2[cursY][cursX - 1] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursX--;
				
			}
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
					printf("%c", puzzle2[i2][j2]);
				}
				printf("\n");
			}	
		}
				
	
		
		
		for (int i = 0; i < PUZZLE_LENGTH; i++)
		{
			for (int j = 0; j < PUZZLE_LENGTH; j++)
			{
				if (puzzle2[i][j] != puzzle[i][j])
				{
					if (!(puzzle2[i][j] == '?' && puzzle[i][j] == '0'))
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
			if (puzzle2[i2][j2] == '?')
					puzzle2[i2][j2] = '0';
			printf("%c", puzzle2[i2][j2]);
		}
		printf("\n");
	}		
	printf("The puzzle has been solved!\n");
	return 0;
}
