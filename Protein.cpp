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
#include "Protein.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

	// constructors and destructor
	Protein::Protein()
	{
		type = Hormon;
	}
	
	Protein::Protein(char * p, Protein_Type atype, int length)
	{
		seq = p;
		type = atype;
		len = length;
	}
	
 	Protein::~Protein()
	{
		seq = NULL;
		delete [] seq;
	}
	// function printing Protein sequence information to user
	void Protein::Print()
	{
		cout << "Strand: ";
        for (int i = 0; i < len; i++)
        {
            cout << seq[i];
        }
        cout << endl;
		cout << "Type: ";
		if (type == Hormon)
		{
			cout << "Hormon" << endl;
		}
		else if (type == Enzyme)
		{
			cout << "Enzyme" << endl;
		}
		else if (type == TF)
		{
			cout << "TF" << endl;
		}
		else if (type == Cellular_Function)
		{
			cout << "Cellular Function" << endl;
		}
	}
	// virtual function printing Protein sequence information to user for operator overloading
	void Protein::Print(ostream& out)
    {
		out << "Strand: ";
        for (int i = 0; i < len; i++)
        {
            out << seq[i];
        }
        out << endl;
		out << "Type: ";
		if (type == Hormon)
		{
			out << "Hormon" << endl;
		}
		else if (type == Enzyme)
		{
			out << "Enzyme" << endl;
		}
		else if (type == TF)
		{
			out << "TF" << endl;
		}
		else if (type == Cellular_Function)
		{
			out << "Cellular Function" << endl;
		}
    }

	// virtual function getting Protein sequence information from user for operator overloading
	void Protein :: GetInput(istream& in)
	{	
		while (1)
		{
			try
			{
				cout<<"Enter the sequence: ";
				char Arr[100];
				in >> Arr;
				CodonsTable cdn;
				for (int i = 0; i < strlen(Arr); i++)
				{
					bool check = false;
					for (int j = 0; j < 64; j++)
					{
						if (Arr[i] == cdn.getCodon(j).AminoAcid && Arr[i] != 'Z' && Arr[i] != 'z')
						{
							check = true;
						}
					}
					if (check == false)	
					{
						string err = "You have entered an invalid character.\n";
						throw err;
					}
				}
				for (int i = 0; i < strlen(Arr); i++)
				{
					seq[i] = Arr[i];
				}
				cout << "\nenter the type (ex: 0 -> Hormon, 1-> Enzyme ,2 -> TF , 3 -> Cellular Function: ";
				int tp;
				in >> tp;
				if (tp == 0)
					type = Hormon;
				else if(tp == 1)
					type =  Enzyme;
				else if(tp == 2)
					type =TF;
				else if (tp == 3)
					type =  Cellular_Function;
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
	void Protein::LoadSequenceFromFile(string fileName)
	{
		ifstream inFile(fileName);
		char tp[20];
		inFile.getline(tp, 20, ':');
		if (tp == "hormon")
		{
			type = Hormon;
		}
		else if (tp == "enzyme")
		{
			type = Enzyme;
		}
		else if (tp == "TF")
		{
			type = TF;
		}
		else if (tp == "cellular_function")
		{
			type = Cellular_Function;
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
	void Protein::SaveSequenceToFile(string fileName)
	{
		ofstream outFile(fileName);
		if (type = Hormon)
		{
			outFile << "hormon";
		}
		else if (type = Enzyme)
		{
			outFile << "enzyme";
		}
		else if (type = TF)
		{
			outFile << "TF";
		}
		else if (type = Cellular_Function)
		{
			outFile << "cellular_function";
		}
		outFile << ":";
		for (int i = 0; i < len; i++)
		{
			outFile << seq[i];
		}
		outFile << ":";
	}

 	// return an array of DNA sequences that can possibly
    // generate that protein sequence
	
	DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA, int& DNACount)
	{
		//vector<string> dnaStrandsToProtein;
		//vector<int> dnaStrandsIndex;
		string temp = ""; // string to carry all characters converted from DNA
		DNA * allStrands = new DNA[bigDNA.getLen()];
		int strandCounter = 0; // count of found DNA strands identical to Protein
		RNA bigRNA = bigDNA.ConvertToRNA();
		CodonsTable cdns;
		int counter = 0;
		// Loop on every 3 characters to check the amino acid character.
		for (int i = 0; i < bigDNA.getLen() - 2; i+=3)
		{
			for (int j = 0; j < 64; j++)
			{
				if (bigRNA.getCharFromSeq(i) == cdns.getCodon(j).value[0] && bigRNA.getCharFromSeq(i + 1) == cdns.getCodon(j).value[1] && bigRNA.getCharFromSeq(i + 2) == cdns.getCodon(j).value[2])
				{	
					temp += cdns.getCodon(j).AminoAcid;
					counter++;

					// if the string length is same of protein length, start checking if it is Identical the protein object
					if (counter == len)
					{
						//dnaStrandsToProtein.push_back(temp);
						//dnaStrandsIndex.push_back(i - len*3);

						bool isEqual = true;
						for (int m = 0; m < len; m++)
						{
							if (temp[m] != seq[m])
							{
								isEqual = false;
								break;
							}
						}
						if (isEqual)
						{
							char * sequence = new char[len*3];
							int seqCount = 0;
							i -= (len-1)*3;
							for (int j = i; j < (i + (len * 3)); j += 3)
							{
								sequence[seqCount++] = bigDNA.getCharFromSeq(bigDNA.getLen() - j - 1);
								sequence[seqCount++] = bigDNA.getCharFromSeq(bigDNA.getLen() - (j + 1) - 1);
								sequence[seqCount++] = bigDNA.getCharFromSeq(bigDNA.getLen() - (j + 2) - 1);
							}

							DNA onePossibility(sequence,promoter, 0, len*3);
							allStrands[strandCounter++] = onePossibility;
							i += ((len-1) * 3); // if it is identical, loop starting from the next character.
							//k += (len * 3 - 1);
						}
						else
						{
							i -= (len - 1)*3 + 2; // if not found start checking again from the index right after the first character taken in the temp string.
						}

						temp = "";
						counter = 0;
						break;
					}
					break;
				}
			}
		}
		DNACount = strandCounter;
		return allStrands;
	}

	//operators overloading
	Protein Protein::operator+ (Protein& rhs)
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
		return Protein(res,type, len + rhs.len);
	}

	bool Protein::operator== (Protein& rhs)
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
	
	bool Protein::operator!= (Protein& rhs)
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
	
	
	/* DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA)
	{
		vector<string> dnaStrandsToProtein;
		string temp = "";
		DNA * allStrands = new DNA[bigDNA.getLen() / 3];
		int strandCounter = 0;
		RNA bigRNA = bigDNA.ConvertToRNA();
		CodonsTable cdns = CodonsTable();
		for (int i = 0; i < bigDNA.getLen(); i += 3)
		{
			for (int j = 0; j < 64; j++)
			{
				if (bigRNA.getCharFromSeq(i) == cdns.getCodon(j).value[0] && bigRNA.getCharFromSeq(i + 1) == cdns.getCodon(j).value[1] && bigRNA.getCharFromSeq(i + 2) == cdns.getCodon(j).value[2])
				{
					if (cdns.getCodon(j).AminoAcid == 'Z')
					{
						dnaStrandsToProtein.push_back(temp);
						temp = "";
						break;
					}	
					temp += cdns.getCodon(j).AminoAcid;
				}
			}
		}
		for (int i = 0; i < dnaStrandsToProtein.size(); i++)
		{
			if (dnaStrandsToProtein[i].length() == len)
			{
				bool isEqual = true;
				for (int j = 0; j < len; j++)
				{
					if (dnaStrandsToProtein[i][j] != seq[j])
					{
						isEqual = false;
						break;
					}
				}
				if (isEqual)
				{
					char * sequence = new char[len*3 + 3];
					int seqCount = 0;
					for (int j = (i*len*3 + 3*strandCounter); j < (i*len*3 + 3*strandCounter + (len * 3) + 3); j += 3)
					{
						sequence[seqCount++] = bigDNA.getCharFromSeq(j);
						sequence[seqCount++] = bigDNA.getCharFromSeq(j + 1);
						sequence[seqCount++] = bigDNA.getCharFromSeq(j + 2);
					}

					DNA onePossibility(sequence,promoter, 0, len*3 + 3);
					allStrands[strandCounter++] = onePossibility;
				}
			}
		}
		return allStrands;
	}
	///
	/* 	// Version that gets all possible sequences.

	DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
	{
		char* dnaStrand = new char[100 * len];
		CodonsTable cdns = CodonsTable();
		for (int i = 0; i < len; i++)
		{
			int counter = 0;
			for (int j = 0; j < 64; j++)
			{
				Codon temp = cdns.getCodon(j);
				if (seq[i] == temp.AminoAcid)
				{
					cdnIndex[i][counter++] = j;
				}
			}
			while (counter <= 5)
			{
				cdnIndex[i][counter++] = -1;
			}
		}
		if (len < 10)
		{
			for (int i = len; i < 10; i++)
			{
				cdnIndex[i][0] = -1;
			}
		}
		int x = 0;
		int poss[6] = {0,0,0,0,0,0};
		recursionEncoding(dnaStrand,x,poss,len-1);
		/*for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (cdnIndex[i][j] == -1)
					break;
				Codon temp = cdns.getCodon(cdnIndex[j][i]);
				dnaStrand[x] = temp.value[0];
				dnaStrand[x + 1] = temp.value[1];
				dnaStrand[x + 2] = temp.value[2];
				cout << dnaStrand[x] << dnaStrand[x + 1] << dnaStrand[x + 2];
			}
			cout << endl;
		}
		return NULL;
	}

	void Protein::recursionEncoding(char* dna, int& ind, int poss[], int AA)
	{
		if (AA < 0)//cdnIndex[AA][poss[AA]] == -1 || AA > len)
			return;
		//else if(AA > len)
			//recursionEncoding(dna,ind,poss + 1, AA - 1);
		for (int i = 0; i < len; i++)
		{
			CodonsTable cdns = CodonsTable();
			Codon temp;
			temp = cdns.getCodon(cdnIndex[i][poss[i]]);
			dna[ind] = temp.value[0];
			dna[ind + 1] = temp.value[1];
			dna[ind + 2] = temp.value[2];
			cout << dna[ind] << dna[ind+1] << dna[ind+2];		
			//cout << temp.value[0] << temp.value[1] << temp.value[2] << endl;
			ind += 3;
		}
		cout << endl;
		//if (cdnIndex[AA][poss[len] + 1] == -1)
		//{
		//	poss[len] = 0;
		//	int x = 1;
		//	while (x < len)
		//	{
		//		poss[len - x]++;
		//		if (cdnIndex[AA][poss[len - x] + 1] == -1)
		//		{
		//			x++;
		//			//poss[len - x]++;
		//		}
		//		else
		//			break;
		//	}
		//	recursionEncoding(dna, ind, poss, AA + 1);
		//}
		++poss[len-1];
		if (AA == 0 && cdnIndex[AA][poss[len-1]] == -1)
		{
			for (int i = len-2; i >= AA; i--)
			{
				if (cdnIndex[AA][poss[i]] != -1)
				{
					++poss[i];
					for (int j = i+1; j < len; j++)
						poss[j] = 0;
					if (cdnIndex[AA][poss[i]] != -1)
						recursionEncoding(dna, ind, poss, AA);
				}
			}
			return;
		}
		/*if (cdnIndex[AA][poss[len-1]] == -1 && AA == 0)
		{
			return;
		}
		else if(cdnIndex[AA][poss[len-1]] == -1)
		{
			poss[AA-1]++;
			for (int i = AA; i < len; i++)
				poss[i] = 0;
			recursionEncoding(dna, ind, poss, AA - 1);
		}
		else
		{
			recursionEncoding(dna, ind, poss, AA);
		}
	}
	*/