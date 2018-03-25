#include <iostream>
#include <string>

// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: Problem 5 ch 3.cpp
// Problem Found in Chapter 3 page 173 in the book "Problem solving with C++" by Walter Savitch 9th Edition
// Last Modification Date: 28/02/2018
// Author and ID and Group: Mark Samuel Shawki 20170206 Group 8
// Teaching Assistant: Mohamed Atta & Ibrahim Zeidan
// Purpose: Prints the Prime numbers from 0 to 100

using namespace std;

int main()
{
	int x = 0;
	while (true)
	{
		cout << 3;
		for (int i = 4; i < 100; i++)
		{
			bool prime = true;
			for (int j = 2; j < ((int)(i/2) + 1); j++)
			{
				if ((i % j) == 0)
				{
					prime = false;
					break;
				}
			}
			if (prime == true)
			{
				cout << ", " << i;
			}
		}
		cout << endl << "if you would like to quit enter 0: ";
		cin.clear();
		cin >> x;
		if (x == 0)
			break;
	}
	return 0;
}