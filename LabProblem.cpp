//M 1000
//D 500
//C 100
//L 50
//X 10
//V 5
//I 1
#include <iostream>
#include <string>
void sortingNumbers();
void RomanToNumbers();
void sortNumbers (int& x, int& y);
void sortNumbers (int& x, int& y, int& z);
void sortNumbers (int& x, int& y, int& z, int& l);

using namespace std;

void main()
{
	sortingNumbers();
	RomanToNumbers();
}

void sortingNumbers()
{
	int x,y,z,l;
	cout << "Please enter 4 numbers to sort:";
	cin >> x >> y >> z >> l;
	sortNumbers(x,y,z,l);
	cout << x << "," << y << "," << z << "," << l << endl;
}

void sortNumbers (int& x, int& y)
{
	if (x>y)
		swap(x,y);
}

void sortNumbers (int& x, int& y, int& z)
{
	sortNumbers(x,y);
	sortNumbers(y,z);
	sortNumbers(x,y);
}

void sortNumbers (int& x, int& y, int& z, int& l)
{
	sortNumbers(x,y,z);
	sortNumbers(y,z,l);
	sortNumbers(x,y,z);
}

void RomanToNumbers()
{
	int sum = 0;
	string input[100];
	cout << "Enter the roman numbers to convert to normal numbers and enter 0 to end:";
	for (int i = 0; i < 100; i++) 
	{
		string x;
		cin >> x;
		if (x == "0"){break;}
		input[i] = x;
	}
	for (int i = 0; i < (sizeof(input)/sizeof(input[0])) - 1; i++) 
	{
		if (input[i].empty()){break;}
		for (int j = 0; j < input[i].length(); j++)
		{
			switch (toupper(input[i][j]))
			{
				case 'M':
					sum += 1000;
					break;
				case 'D':
					sum += 500;
					break;
				case 'C':
					sum += 100;
					break;
				case 'L':
					sum += 50;
					break;
				case 'X':
					sum += 10;
					break;
				case 'V':
					sum += 5;
					break;
				case 'I':
					if (input[i].length() - 1 == j)
					{
						sum += 1;
					}
					else
					{ 
						if(toupper(input[i][j+1]) == 'I')
						{
							sum += 1;
						}
						else
						{
							sum -= 1;
						}
					}
					break;
			}
		}
		cout << sum << endl;
		sum = 0;
	}
}