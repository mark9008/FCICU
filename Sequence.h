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

#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Sequence
{
  	protected:
        char * seq;
        int len;
    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
		// setters and getters
		void setLen(int length);
		int getLen();
		char getCharFromSeq(int index);
 	 	// pure virtual functions that should be overridden because every
        // type of sequence has its own details to be printed, saved, loaded or taken as input
        virtual void Print()= 0;
		virtual void Print(ostream& out)= 0;
		virtual void GetInput(istream& in)= 0;
		virtual void LoadSequenceFromFile(string fileName) = 0;
		virtual void SaveSequenceToFile(string fileName) = 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2, int& length);
		friend istream& operator>> (istream& in, Sequence& seqIn);
		friend ostream& operator<< (ostream& out, Sequence& seqOut);
};


#endif // SEQUENCE_H_INCLUDED
