// polybius square cipher.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <string>

// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: polybius square cipher.cpp
// Last Modification Date: 28/02/2018
// Author and ID and Group: Mark Samuel Shawki 20170206 Group 8
// Teaching Assistant: Mohamed 'Ata & Ibrahim Zeidan
// Purpose: Ciphers and deciphers sentances using polybius square cipher

using namespace std;

// Declarations for Keys!

char alpha[25] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','y','z'}; // The alphabet
char letters[5][5]; // 5x5 Square [rows][columns] respectively.
int keys[5]; 

int setKeys() // function that sets the keys and arranges the alphabet in the square.
{
	cout << "Enter The Key to use for encoding your words: ";
	cin >> keys[0] >> keys[1] >> keys[2] >> keys[3] >> keys[4]; // the 5 input numbers of the keys ex: 5 2 4 3 1.
	int counter = 0; // counter for alpha Array
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			letters[i][j] = alpha[counter]; // i --> rows, j --> columns.
			counter++;
		}
	}
	return 0;
}


int main()
{
	setKeys(); // call the function to arrange letters and take the keys.
	cout << "Welcome to Polybius Square Cipher/Decipher!\n1- Cipher from English to Polybius Square Cipher\n2- Decipher from Polybius Square Cipher to English" << endl; // program start and definition
	int chosen;
	cin >> chosen;
	while ((chosen != 1) && (chosen != 2)) // if the user entered wrong choice.
	{
		cout << "Wrong Choice please enter only 1 or 2!" << endl;
		cin.clear(); 
		cin.ignore(); // these two lines to clear and reset the cin if it has any wrong input.
		cin >> chosen;
	}
	if (chosen == 1) // Cipher Choice:
	{
		cout << "Please enter the English sentance to be translated into Polybius Square Cipher: " << endl;
		char sentance[100];
		cin.getline(sentance,100,'\n');
		cin.getline(sentance,100,'\n'); // Read Sentance to cipher from user.
		for (int i = 0; i < 100; i++)
		{
			if (sentance[i] != ' ') // ignores spaces.
			{
				for (int row = 0; row < 5; row++)
				{
					for (int col = 0; col < 5; col++)
					{
						if (sentance[i] == letters[row][col]) // finding the position of each letter.
						{
							cout << keys[row]  << keys[col]; // calling the real position entered by user.
						}
					}
				}
			}
			else
				cout << " "; // prints the White space as it is.
		}
	}
	else
	{
		cout << "Please enter the numbers you want to decipher into English and enter '0' to End Translation: " << endl;
		string words[100]; // the output.
		int nums[100]; // the input.
		for (int i = 0; i < 100; i++) // For each word in the input
		{
			cin >> nums[i];
			
			if (nums[i] == 0)
			{break;} // ends the program when 0 is entered.
			
			long long int sum; // long long if it is a long word.
			sum = nums[i];
			while (sum > 0) // loops on the word.
			{
				int row, col;	
				row = (sum % 100)/10; // takes the digit before the last one.
				col = sum % 10; // takes the last digit.
				sum /= 100; // deletes the last 2 numbers from the word.
				int realr, realc;
				for (int rr = 0; rr < 5; rr++)
				{
					if (keys[rr] == row) // compares the input number with its position in the input keys.
					{
						realr = rr; 
						break; // returns when the Real Row is found.
					}
				}
				for (int rc = 0; rc < 5; rc++)
				{
					if (keys[rc] == col) // compares the input number with its position in the input keys.
					{
						realc = rc;
						break; // returns when the Real column is found.
					}
				}

				words[i].insert(0, 1, letters[realr][realc]); // puts the letter in the beginning of the word because I Get the numbers from right to left.
			}
			cout << words[i] << ' '; // print the word then space after it
		}
	}
	return 0;
}

