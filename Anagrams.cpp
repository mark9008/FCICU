// Anagrams.cpp : Defines the entry point for the console application.
//

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

