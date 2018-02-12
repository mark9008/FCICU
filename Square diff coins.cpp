#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;
int random(int min,int max)
{
	int seed = static_cast<int>(time(0));
	srand(seed);
	return rand() % max + min;
}

int main()
{
	int n,p1,p2,R,pl = 0;
	cout << "Hello, this is subtracting squares game!! \nRules: \nthe game starts with a number between 1 and 50, and players will take turns to subtract from that number a square of numbers from 1 to 6. \nthe Available possible numbers to subtract are: (1,4,9,16,25,36)";
	R=1;
	while (R == 1){
		cout << "do you like 1 player or 2 players? \n 1: For 1 player \n 2: For 2 players \n 3: Exit \n ";
		cin >> pl;
		while ((pl != 1) && (pl != 2) && (pl != 3)){
			cout << "Please enter 1, 2 or 3 only: ";
			cin >> pl;
		}
		n = random(1,50);
		if (pl == 1){
			cout << "The number to start with is " << n << endl;
			while (n != 0){
				while (true){
					cout << "Player 1's turn, Enter a number from 1 to 6: ";
					cin >> p1;
					if ((p1 < 1) || (p1 > 6)){
						cout << "Error!" << endl;
					}
					else{
						if (pow(p1,2.0) > n){
							cout << "Error! You chose to subtract " << pow(p1,2.0) << " which is greater than the current number!" << endl;
						}
						else{
							n -= pow(p1,2.0);
							cout << "The number now is : " << n << endl;
							break;
							}
					}
				}
				if (n == 0){
					cout << "Player 1 wins!!" << endl;
					break;
				}
				while (true){
					if ((n == 1) || (n == 4) || (n == 9) || (n == 16) || (n == 25) || (n == 36)){
						p2 = n;
					}
					else{
						p2 = random(1,6);
					}
					if (pow(p2,2.0)>n){
						p2 = random(1,6);
					}
					else{
						cout << "Computer's turn, chosen number is: " << p2 << endl;
						n -= pow(p2,2.0);
						cout << "The number now is : " << n << endl;
						break;
					}
				}
				if (n == 0){
					cout << "Computer wins!!" << endl;
					break;
				}
			}
		}
		else if (pl == 2){
			cout << "The number to start with is " << n << endl;
			while (n != 0){
				while (true){
					cout << "Player 1's turn, Enter a number from 1 to 6: ";
					cin >> p1;
					if ((p1 < 1) || (p1 > 6)){
						cout << "Error!" << endl;
					}
					else{
						if (pow(p1,2.0) > n){
							cout << "Error! You chose to subtract " << pow(p1,2.0) << " which is greater than the current number!" << endl;
						}
						else{
							n -= pow(p1,2.0);
							cout << "The number now is : " << n << endl;
							break;
							}
					}
				}
				if (n == 0){
					cout << "Player 1 wins!!" << endl;
					break;
				}
				while (true){
					cout << "Player 2's turn, Enter a number from 1 to 6: ";
					cin >> p2;
					if ((p2 < 1) || (p2 > 6)){
						cout << "Error!" << endl;
					}
					else{
						if (pow(p2,2.0) > n){
							cout << "Error! You chose to subtract " << pow(p2,2.0) << " which is greater than the current number!" << endl;
						}
						else{
							n -= pow(p2,2.0);
							cout << "The number now is : " << n << endl;
							break;
							}
					}
				}
				if (n == 0){
					cout << "Player 2 wins!!" << endl;
					break;
				}
			}
		}
		else if (pl == 3){
			break;
		}
		cout << "If you would like to play again enter 1!" << endl;
		cin >> R;
	}
	return 0;
}

