// Course:  CS213 - Programming II  - 2018
// Title:   Assignment IV
// Program: Assignment 4 Prog 2
// Purpose: Biological information analysis
// Author 1:  Mark Samuel Shawki
// ID: 20170206
// Author 2:  Mario Osama Fayez
// ID: 20170209
// Author 3:  Mark Ehab Ayad
// ID: 20170205
// Date:    12 December 2018
// Version: 1.0

#include "Sequence.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
    // constructors and destructor
    Sequence::Sequence()
    {
        seq = new char('\0');
        len = 0;
    }
    Sequence::Sequence(int length)
    {
        seq = new char[length];
        len = length;
    }
    Sequence::Sequence(Sequence& rhs)
    {
        seq = new char[rhs.len];
        for (int i = 0; i < len; i++)
        {
            seq[i] = rhs.seq[i];
        }
        len = rhs.len;
    }
    Sequence::~Sequence()
    {
		seq = NULL;
        delete [] seq;
    }

	void Sequence::setLen(int length)
	{
		len = length;
	}

	int Sequence::getLen()
	{
		return len;
	}

	char Sequence::getCharFromSeq(int index)
	{
		return seq[index];
	}
    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism
	int max(int a, int b) 
	{ 
		return (a > b)? a : b; 
	} 

	int lcs(char *X, char *Y, int m, int n,int** t) 
	{ 
		int i, j; 
		
		/* Following steps build L[m+1][n+1] in bottom up fashion. Note  
			that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
		for (i=0; i<=m; i++) 
		{ 
			for (j=0; j<=n; j++) 
			{ 
				if (i == 0 || j == 0) 
					t[i][j] = 0; 
				else if (X[i-1] == Y[j-1]) 
					t[i][j] = t[i-1][j-1] + 1; 
				else
					t[i][j] = max(t[i-1][j], t[i][j-1]); 
			} 
		} 
		return t[m][n];
	} 

    char* Align(Sequence * s1, Sequence * s2, int& length)
	{		
		string res = "";
		int** taken = new int* [s1->len+1];
		for (int i = 0; i < s1->len+1; i++)
		{
			taken[i] = new int[s2->len+1];
		}
		for (int i = 0; i < s1->len; i++)
		{
			for (int j = 0; j < s2->len; j++)
			{
				taken[i][j] = 0;
			}
		}
		int cn = lcs(s1->seq, s2->seq, s1->len, s2->len,taken); 
		int LCS = cn;
		for (int i = s1->len; i > 0; i--)
		{
			for (int j = s2->len; j > 0; j--)
			{
				if (taken[i][j] == cn && s1->seq[i-1] == s2->seq[j-1])
				{
					cn--;
					res += s1->seq[i-1];
					break;
				}
			}
		}

		char* result = new char[LCS];
		for (int i = LCS; i > 0; i--)
		{
			result[LCS-i] = res[i-1];
		}
		length = LCS;
		return result;
	}

	istream& operator>> (istream& in, Sequence& seqIn)
	{
		seqIn.GetInput(in);
		return in;
	}

	ostream& operator<< (ostream& out,Sequence& seqOut)
	{
		seqOut.Print(out);
		return out;
	}