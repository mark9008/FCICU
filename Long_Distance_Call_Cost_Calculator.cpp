// Long_Distance_Call_Cost_Calculator.cpp : Defines the entry point for the console application.
//


// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: Long_Distance_Call_Cost_Calculator.cpp
// Problem number 1 Found in Chapter 3 page 174 in the book "Problem solving with C++" by Walter Savitch 9th Edition
// Last Modification Date: 28/02/2018
// Author1 and ID and Group: Mark Samuel Shawki 20170206 Group 8
// Author2 and ID and Group: Mark Ehab Ayad 20170205 Group 8
// Author3 and ID and Group: Muhammed Ahmed Tarek 20170213 Group 8
// Teaching Assistant: Mohamed 'Ata & Ibrahim Zeidan
// Purpose: Calculates the Cost of Long distance Calls

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x = 0;
	cout << "Welcome to Long Distance Call Cost Calculator!!" << endl;
	while (true)
	{
		int nMin, startTime;
		char inputTime[2];
		string day;
		cout << "Enter the length of the call in nMinutes: ";
		cin >> nMin; // Get number of minutes from user
		cout << endl << "Enter the Day of the call: ";
		cin >> day; // Get Day from the user
		float cost;
		if (day == "Sa" || day == "SA" || day == "sa" || day == "Su" || day == "SU" || day == "su") // If the day is Saturday or Sunday
		{
			cost = 0.15 * nMin;
		}
		else // If the day is between Monday and Friday
		{
			cout << endl << "Enter the start time of the call in 24 hours format: ";
			cin.getline(inputTime,2,':'); // Gets the start time from user
			startTime = (int)(inputTime);
			if (startTime < 8 || startTime > 18) // If the time was before 8 AM or after 6 PM
			{
				cost = 0.25 * nMin;
			}
			else // If the time was between 8 AM and 6 PM
			{
				cost = 0.40 * nMin;
			}
		}
		cout << "The Cost of this call is: $" << cost << endl;
		cout << "Now if you would like to Calculate another call Enter 1, if you would like to quit enter 0: ";
		cin.clear();
		cin >> x;
		if (x == 0)
			break;
	}
	return 0;
}

