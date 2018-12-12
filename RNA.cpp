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

#include "RNA.h"
#include <fstream>
using namespace std;
    // constructors and destructor
    RNA::RNA()
    {
        type = mRNA;
    }
    RNA::RNA(char * sequence, RNA_Type atype, int length)
    {
        seq = sequence;
        type = atype;
    }
    RNA::RNA(RNA& rhs)
    {
        seq = rhs.seq;
        type = rhs.type;
		len = rhs.len;
    }
    RNA::~RNA()
    {
		seq = NULL;
        delete [] seq;
    }
    // function to be overridden to print all the RNA information
    void RNA::Print()
    {
		cout << "Strand: ";
        for (int i = 0; i < len; i++)
        {
            cout << seq[i];
        }
        cout << endl;
		cout << "Type: ";
		if (type == mRNA)
		{
			cout << "mRNA" << endl;
		}
		else if (type == pre_mRNA)
		{
			cout << "pre mRNA" << endl;
		}
		else if (type == mRNA_exon)
		{
			cout << "mRNA exon" << endl;
		}
		else if (type == mRNA_intron)
		{
			cout << "mRNA intron" << endl;
		}
    }

	// virtual function printing RNA sequence information to user for operator overloading
	void RNA::Print(ostream& out)
    {
		out << "Strand: ";
        for (int i = 0; i < len; i++)
        {
            out << seq[i];
        }
        out << endl;
		out << "Type: ";
		if (type == mRNA)
		{
			out << "mRNA" << endl;
		}
		else if (type == pre_mRNA)
		{
			out << "pre mRNA" << endl;
		}
		else if (type == mRNA_exon)
		{
			out << "mRNA exon" << endl;
		}
		else if (type == mRNA_intron)
		{
			out << "mRNA intron" << endl;
		}
    }
	// virtual function getting RNA sequence information from user for operator overloading
	void RNA:: GetInput(istream& in)
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
					if (Arr[i] != 'A' && Arr[i] != 'a' && Arr[i] != 'U' && Arr[i] != 'u' && Arr[i] != 'G' && Arr[i] != 'g' && Arr[i] != 'C' && Arr[i] != 'c')
					{
						string err = "You can't enter characters except: A G U C.\n";
						throw err;
					}
				}
				for (int i = 0; i < strlen(Arr); i++)
				{
					seq[i] = Arr[i];
				}
				cout<<"enter the type (ex: 0 -> mRNA, 1-> pre mRNA ,2 ->mRNA xoen , 3 -> mRNA intron "<<endl;
				int tp;
				in >> tp;
				if (tp == 0)
					type = mRNA;
				else if(tp == 1)
					type = pre_mRNA;
				else if(tp == 2)
					type = mRNA_exon ;
				else if (tp == 3)
					type = mRNA_intron;
				else 
				{
					in.clear();
					in.clear();
					string err = "You can enter only these numbers: 0,1,2,3.\n";
					throw err;
				}
				len = strlen(Arr);
				break;
			}
			catch (string err)
			{
				cout << "Error! " << err;
			}
		}
	}
	// function to load sequence from file
	void RNA::LoadSequenceFromFile(string fileName)
	{
		ifstream inFile(fileName);
		char tp[20];
		inFile.getline(tp, 20, ':');
		if (tp == "mRNA")
		{
			type = mRNA;
		}
		else if (tp == "mRNA_exon")
		{
			type = mRNA_exon;
		}
		else if (tp == "mRNA_intron")
		{
			type = mRNA_intron;
		}
		else if (tp == "pre_mRNA")
		{
			type = pre_mRNA;
		}
		char Arr[100];
		inFile.getline(Arr, 100, ':');
		seq = new char[strlen(Arr)];
		for (int i = 0; i < strlen(Arr); i++)
		{
			seq[i] = Arr[i];
		}
		len = strlen(Arr);
	}
	// function to save sequence to file
	void RNA::SaveSequenceToFile(string fileName)
	{
		ofstream outFile(fileName);
		if (type = mRNA)
		{
			outFile << "mRNA";
		}
		else if (type = mRNA_exon)
		{
			outFile << "mRNA_exon";
		}
		else if (type = mRNA_intron)
		{
			outFile << "mRNA_intron";
		}
		else if (type = pre_mRNA)
		{
			outFile << "pre_mRNA";
		}
		outFile << ":";
		for (int i = 0; i < len; i++)
		{
			outFile << seq[i];
		}
		outFile << ":";
	}

    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    Protein RNA::ConvertToProtein(CodonsTable & table)
	{
		char * AA;
		AA = new char[len/3];
		int newLen = 0;
		for (int i = 0; i < len; i+=3)
		{
			for (int j = 0; j < 64; j++)
			{
				if(seq[i] == table.getCodon(j).value[0] && seq[i + 1] == table.getCodon(j).value[1] && seq[i + 2] == table.getCodon(j).value[2]);
				{
					if (table.getCodon(j).AminoAcid == 'Z')
					{
						Protein res(AA,Hormon,newLen);
						return res;
					}
					AA[newLen++] = table.getCodon(j).AminoAcid;
				}
			}
		}
	}
    // function to convert the RNA sequence back to DNA
    DNA RNA::ConvertToDNA()
    {
        char *dnaS = new char[len];
        for (int i = 0; i < len; i++)
        {
            dnaS[i] = seq[i];
            if (seq[i] == 'u' || seq[i] == 'U'){
                dnaS[i] = 'T';
            }
        }
        DNA res(dnaS,promoter,0,len);
        delete [] dnaS;
        return res.getComplementaryStrand();
    }

	//operators overloading
	RNA RNA::operator+ (RNA& rhs)
	{
		char* res = new char[len + rhs.len];
		for (int i = 0; i < len; i++)
		{
			res[i] = seq[i];
		}
		for (int i = 0; i < rhs.len; i++)
		{
			res[i + len] = rhs.seq[i];
		}
		return RNA(res,type, len + rhs.len);
	}

	bool RNA::operator== (RNA& rhs)
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
	
	bool RNA::operator!= (RNA& rhs)
	{
		if (rhs.len == len && rhs.type == type)
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
