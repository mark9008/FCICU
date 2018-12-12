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

#ifndef RNA_H_INCLUDED
#define RNA_H_INCLUDED

#include "Sequence.h"
#include "DNA.h"
#include "protein.h"
#include "Codon.h"

class Protein;
class DNA;
class CodonsTable;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * sequence, RNA_Type atype, int length);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
		void Print(ostream& out);
		void GetInput(istream& in);
		void LoadSequenceFromFile(string fileName);
		void SaveSequenceToFile(string fileName);
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
		// operators overloading
		RNA operator+ (RNA& rhs);
		bool operator== (RNA& rhs);
		bool operator!= (RNA& rhs);
};


#endif // RNA_H_INCLUDED
