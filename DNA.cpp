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

#include "DNA.h"
#include <fstream>
using namespace std;
    // constructors and destructor
    DNA::DNA()
    {
        type = promoter;
        startIndex = -1;
        endIndex = -1;
		len = 1;
    }

    DNA::DNA(char * sequence, DNA_Type atype, int stIndex, int eIndex)
    {
        seq = sequence;
        type = atype;
        startIndex = stIndex;
        endIndex = eIndex;
        len = eIndex - stIndex;
        BuildComplementaryStrand();
    }

    DNA::DNA(DNA& rhs)
    {
        seq = rhs.seq;
        type = rhs.type;
        startIndex = rhs.startIndex;
        endIndex = rhs.endIndex;
        len = rhs.len;
		complementary_strand = rhs.complementary_strand;
    }

    DNA::~DNA()
    {
        seq = NULL;
		delete seq;
        complementary_strand = NULL;
		delete complementary_strand;
    }

    // function printing DNA sequence information to user
     void DNA::Print()
    {
		cout << "Strand: ";
        for (int i = startIndex; i < endIndex; i++)
        {
            cout << seq[i];
        }
		cout << endl << "Complementary Strand: ";
		for (int i = 0; i < len; i++)
        {
            cout << complementary_strand->seq[i];
        }
		cout << endl;
		cout << "Start Index: " << startIndex << endl;
		cout << "End Index: " << endIndex << endl;
		cout << "Type: ";
		if (type == promoter)
		{
			cout << "Promoter" << endl;
		}
		else if (type == motif)
		{
			cout << "Motif" << endl;
		}
		else if (type == tail)
		{
			cout << "Tail" << endl;
		}
		else if (type == noncoding)
		{
			cout << "Noncoding" << endl;
		}
		
    }
	// virtual function printing DNA sequence information to user for operator overloading
	void DNA::Print(ostream& out)
    {
		out << "Strand: ";
        for (int i = startIndex; i < endIndex; i++)
        {
            out << seq[i];
        }
		out << endl << "Complementary Strand: ";
		for (int i = startIndex; i < endIndex; i++)
        {
            out << complementary_strand->seq[i];
        }
        out << endl;
		out << "Start Index: " << startIndex << endl;
		out << "End Index: " << endIndex << endl;
		out << "Type: ";
		if (type == promoter)
		{
			out << "Promoter" << endl;
		}
		else if (type == motif)
		{
			out << "Motif" << endl;
		}
		else if (type == tail)
		{
			out << "Tail" << endl;
		}
		else if (type == noncoding)
		{
			out << "Noncoding" << endl;
		}
    }
	// virtual function getting DNA sequence information from user for operator overloading
	void DNA:: GetInput(istream& in)
	{	
		while (1)
		{
			try
			{
				cout<<"enter the sequence"<<endl;
				char Arr[100];
				in >> Arr;
				if ((strlen(Arr) % 3) != 0 )
				{
					string err = "The sequence length must be multiple of 3.";
					throw err;
				}
				for (int i = 0; i < strlen(Arr); i++)
				{
					if (Arr[i] != 'A' && Arr[i] != 'a' && Arr[i] != 'T' && Arr[i] != 't' && Arr[i] != 'G' && Arr[i] != 'g' && Arr[i] != 'C' && Arr[i] != 'c')
					{
						string err = "You can't enter characters except: A G T C.\n";
						throw err;
					}
				}
				for (int i = 0; i < strlen(Arr); i++)
				{
					seq[i] = Arr[i];
				}
				cout<<"enter the type (ex: 0 -> Promoter, 1-> motif ,2 ->tail , 3 -> Noncoding "<<endl;
				int tp;
				in >> tp;
				if (tp == 0)
					type = promoter;
				else if(tp == 1)
					type = motif;
				else if(tp == 2)
					type =tail ;
				else if (tp == 3)
					type = noncoding;
				else
				{
					in.clear(); // clear buffer
					in.clear();
					string err = "You can enter only these numbers: 0,1,2,3.\n";
					throw err;
				}		
				cout<<"enter the start index"<<endl;
				in >> startIndex;
				cout<<"enter the end index"<<endl;
				in >> endIndex; 
				len = strlen(Arr);
				BuildComplementaryStrand();
				break;
			}
			catch (string err)
			{
				cout << "Error! " << err;
			}
		}
	}
	// function to load sequence from file
	void DNA::LoadSequenceFromFile(string fileName)
	{
       ifstream inFile(fileName);
		char tp[10];
		inFile.getline(tp, 10, ':');
		if (tp == "promoter")
		{
			type = promoter;
		}
		else if (tp == "motif")
		{
			type = motif;
		}
		else if (tp == "tail")
		{
			type = tail;
		}
		else if (tp == "noncoding")
		{
			type = noncoding;
		}
		char Arr[100];
		inFile.getline(Arr, 100, ':');
		seq = new char[strlen(Arr)];
		for (int i = 0; i < strlen(Arr); i++)
		{
			seq[i] = Arr[i];
		}
		int st,end;
		char dummy; // char for the : delimiter
		inFile >> st >> dummy >> end;
		len = strlen(Arr);
		startIndex = st;
		endIndex = end;
	}
	// function to save sequence to file
	void DNA::SaveSequenceToFile(string fileName)
	{
		ofstream outFile(fileName);
		if (type = promoter)
		{
			outFile << "promoter";
		}
		else if (type = motif)
		{
			outFile << "motif";
		}
		else if (type = tail)
		{
			outFile << "tail";
		}
		else if (type = noncoding)
		{
			outFile << "noncoding";
		}
		outFile << ":";
		for (int i = 0; i < len; i++)
		{
			outFile << seq[i];
		}
		outFile << ":";
		outFile << startIndex << ":" << endIndex << ":";
	}

    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA DNA::ConvertToRNA()
    {
        char *rnaS = new char[len];
        for (int i = startIndex; i < endIndex; i++)
        {
			//cout << complementary_strand->seq[i];
            rnaS[i] = complementary_strand->seq[i];
            if (complementary_strand->seq[i] == 't' || complementary_strand->seq[i] == 'T'){
                rnaS[i] = 'U';
            }
        }
        RNA res(rnaS,mRNA,len);
		rnaS = NULL;
        delete [] rnaS;
        return res;
    }
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void DNA::BuildComplementaryStrand()
    {
        char *cs = new char[len];
        for (int i = 0; i < len; i++)
        {
            if (seq[i] == 'a' || seq[i] == 'A'){
                cs[len - i - 1] = 'T';
            }
            if(seq[i]== 'c' || seq[i]== 'C'){
                cs[len - i - 1]='G';
            }
            if(seq[i]== 't' || seq[i]== 'T'){
                cs[len - i - 1]='A';
            }
            if(seq[i]== 'g' || seq[i]== 'G'){
                cs[len - i - 1]='C';
            }
        }
        complementary_strand = new DNA();
        complementary_strand->seq = cs;
        complementary_strand->type = type;
        complementary_strand->startIndex = startIndex;
        complementary_strand->endIndex = endIndex;
		complementary_strand->len = len;
        complementary_strand->complementary_strand = this;
		cs = NULL;
        delete cs;
    }
	
	DNA DNA::getComplementaryStrand()
	{
		return	*complementary_strand;
	}

	//operators overloading
	DNA DNA::operator+ (DNA& rhs)
	{
		char* res = new char[len + rhs.len];
		for (int i = startIndex; i < endIndex; i++)
		{
			res[i] = seq[i];
		}
		int counter = 0;
		for (int i = rhs.startIndex; i < rhs.endIndex; i++)
		{
			res[(counter++) + len] = rhs.seq[i];
		}
		return DNA(res,type,0,len + rhs.len);
	}

	bool DNA::operator== (DNA& rhs)
	{
		if (rhs.len == len && rhs.type == type)
		{
			for (int i = 0; i < len; i++)
			{
				if (seq[i] != rhs.seq[i])
					return false;
			}
			return true;
		}
		return false;
	}
	
	bool DNA::operator!= (DNA& rhs)
	{
		if (rhs.len == len)
		{
			for (int i = 0; i < len; i++)
			{
				if (seq[i] != rhs.seq[i])
					return true;
			}
			return false;
		}
		return true;
	}
