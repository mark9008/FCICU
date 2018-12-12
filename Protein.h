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

#ifndef PROTEIN_H_INCLUDED
#define PROTEIN_H_INCLUDED

#include "Sequence.h"
#include "DNA.h"

class DNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
		//int cdnIndex[10][6];
    public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p, Protein_Type atype, int length);
 	 	~Protein();
		void Print();
		void Print(ostream& out);
		void GetInput(istream& in);
		void LoadSequenceFromFile(string fileName);
		void SaveSequenceToFile(string fileName);
 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(DNA & bigDNA, int& DNACount);
		//void recursionEncoding(char* dna, int& ind, int poss[], int AA);
		
		// operators overloading
		Protein operator+ (Protein& rhs);
		bool operator== (Protein& rhs);
		bool operator!= (Protein& rhs);
};


#endif // PROTEIN_H_INCLUDED
