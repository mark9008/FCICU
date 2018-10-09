// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 3 - Problem 6
// Program: CS213-2018-A1-T1-P2
// Purpose: check if two phrases are anagrams or not
// 	    Anagrams: two phrases with same letters but different arrangement of letters.
// Author:  Mark Samuel Shawki
// Date:    9/10/2018
// Version: 1.0

#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	char x[100],y[100];
	cout << "Enter your first phrase and end it with '0': ";
	cin.getline(x,100,'0');
	cout << "Enter your second phrase and end it with '0': ";
	cin.getline(y,100,'0');
	int alpha1[26], alpha2[26];
	for (int i = 0; i < 26; i++) {
		alpha1[i] = 0;
		alpha2[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		int n = (int)x[i];
		if ((n >= 'A') && (n < 'Z')) {
			alpha1[n - 65]++;
		} else if ((n >= 'a') && (n < 'z')) {
			alpha1[n - 97]++;
		}
	}
	for (int i = 0; i < 100; i++) {
		int n = (int)y[i];
		if ((n >= 'A') && (n < 'Z')) {
			alpha2[n - 65]++;
		} else if ((n >= 'a') && (n < 'z')) {
			alpha2[n - 97]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (alpha1[i] != alpha2[i]) {
			cout << "The 2 phrases are not Anagrams!";
			return 0;
		}
	}
	cout << "The 2 phrases are Anagrams!";
	return 0;
}

