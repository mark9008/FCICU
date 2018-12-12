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

#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED

#include <iostream>
#include "Sequence.h"
#include "RNA.h"

using namespace std;
class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(char * seq, DNA_Type atype, int stIndex = 0, int eIndex = 23);
        DNA(DNA& rhs);
        ~DNA();
 	 	// function printing DNA sequence information to user
        void Print();
		void Print(ostream& out);
		void GetInput(istream& in);
		void LoadSequenceFromFile(string fileName);
		void SaveSequenceToFile(string fileName);
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
		// function that returns Complementary strand as a DNA
		DNA getComplementaryStrand();
		
		// operators overloading
		DNA operator+ (DNA& rhs);
		bool operator== (DNA& rhs);
		bool operator!= (DNA& rhs);
  };



#endif // DNA_H_INCLUDED
