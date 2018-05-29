#include <iostream>
#include<string.h>
using namespace std;


void display(char word[], int size)
{

	for (int i = 0; i < size; i++)
		cout << word[i];
	cout << endl;



}


bool checkGuess(char c, char ans[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (c == ans[i])
			return true;

	}
	return false;
}



void revealLetter(char c, char ans[], char word[], int size, int &revealed)
{

	for (int i = 0; i < size; i++)

	{

		if (c == ans[i])
		{
			word[i] = ans[i];
			revealed++;
		}
	}
}

int main()
{
	char answer[] = "paradox";
	const int SIZE = strlen(answer);
	char word[SIZE + 1];
	for (int i = 0; i < SIZE; i++)
		word[i] = '*';
	int guesses = 20;
	int revealed = 0;
	char guess = '0';

	cout << " Guess the word: " << word << endl;
	while (guesses > 0 && revealed < SIZE)
	{
		cout << " You have " << guesses << " guesses left" << endl;
		cin >> guess;
		if (checkGuess(guess, answer, SIZE))
		{
			cout << "Great job. You releaved a letter!" << endl;
			revealLetter(guess, answer, word, SIZE, revealed);
			display(word, SIZE);
		}
		guesses--;
	}

	if (revealed == SIZE)
	{
		cout << "You WIN\n";
	}

	else
	{
		cout << "You loose" << endl;
		cout << "The word is ";
		display(answer, SIZE);
	}
	return 0;
}


