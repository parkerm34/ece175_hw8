/*	Author: Parker Mathewson
 *	Date: 3/23/12
 *	Comments: This is a program to play a game along the lines of hangman.
 *			I figure this may take 3 arrays. You must tell them if
 *			the guess is correct, and if so how many times the
 *			guess appears in your word.
 */
#include <stdio.h>
#define WORD_LENGTH 6

char print_and_guess(char guess)
{
	printf("Guess a letter: ");
	fflush(stdin);
	scanf("%c", &guess);
	return guess;
}

void letter_appearance(char guess, int appearances)
{
	if(appearances == 1)
	{
		printf("Letter %c appears %d time in the word.\n", guess, appearances);
	}
	else
	{
		printf("Letter %c appears %d times in the word.\n", guess, appearances);
	}
}

int unhide_letters(char *secret_word, char *secret_word_hidden, char guess, int number_of_letters, int wrong)
{
	int i=0, j=0;

	for(i=0; i<number_of_letters; i++)
	{
		if(guess == secret_word[i])
		{
			secret_word_hidden[i] = guess;
			j++;
		}
	}

	if(j == 0)
	{
		wrong++;
	}

	letter_appearance(guess, j);
	return wrong;
}

int main(void)
{
	char secret_word[]="rhythm";
	char secret_word_hidden[]="******";
	char guess;
	int wrong=0, i=0, j=0;

	printf("The secret word is:\n%s\n", secret_word_hidden);

	while (wrong !=6)
	{
		j=0;
		guess = print_and_guess(guess);
		wrong = unhide_letters(secret_word, secret_word_hidden, guess, WORD_LENGTH, wrong);
		printf("%s\n", secret_word_hidden);
		for(i=0; i<WORD_LENGTH; i++)
		{
			if(secret_word_hidden[i] == secret_word[i])
			{
				j++;
			}
			if(j == 6)
			{
				printf("You did it!\n");
				return 0;
			}
		}


		if(wrong == 6)
		{
			printf("Sorry. Game over.\n");
			return 0;
		}
	}
}



