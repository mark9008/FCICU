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

#include <iostream>

#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Codon.h"
#include "Protein.h"

using namespace std;

int main()
{
	/*	//char* seq = new char[10];
	//seq = "TTATTTTTTTTATTTTTT";
	//DNA test(seq, promoter, 0, 18);
	////test.Print();
	//RNA test2 = test.ConvertToRNA();
	////test2.Print();
	//CodonsTable codontbl = CodonsTable();
	//Codon cdn = codontbl.getCodon(0);
	////cout << cdn.AminoAcid << " " << cdn.value[0] << cdn.value[1] << cdn.value[2] << endl;
	//Protein pr("KK", Hormon, 2);
	//DNA * DNAfromProtein = pr.GetDNAStrandsEncodingMe(test);
	//for (int i = 0; i < 2; i++)
	//{
	//	DNAfromProtein[i].Print();
	//	cout << endl;
	//}
	//char* s1;
	//char* s2;
	//s1 = new char[6];
	//s2 = new char[7];
	//s1 = "AGGTAB";
	//s2 = "GXTXAYB";
	//DNA seq1(s1,promoter, 0, 7);
	//DNA seq2(s2,promoter, 0, 8);
	////cin >> input;
	//int lcs;
	//char * f = Align(&seq1,&seq2,lcs);
	//for (int i = 0; i < lcs; i++)
	//	cout << f[i];
	//Sequence* tt = new DNA(seq,promoter,0,18*2);
	//cout << (tt != tt);
	DNA pIn;
	cin >> pIn;
	pIn.Print();
	cout << pIn;*/
	while (1)
	{
		try 
		{
main_menu:	cout << "Welcome to Biological Information Analysis System!\n"
				 << "Please choose the number of operation you would like to perform from below:\n"
				 << "\t1- Input Sequence.\n"
				 << "\t2- Load Sequence From File.\n"
				 << "\t(-1)- Exit.\n" ;
			string choice = "-1";
			cin >> choice;
			DNA inDNA;
			RNA inRNA;
			Protein inProtein;
			string DNAF;
			string RNAF;
			string ProteinF;
			if (stoi(choice) == -1)
				break;
			else if(stoi(choice) == 1)
			{
				cout << "Please choose type of Sequence you want to input:\n"
					 << "\t1- DNA.\n"
					 << "\t2- RNA.\n"
					 << "\t3- Protein.\n";
				string seqType;
				cin >> seqType;
				if (stoi(seqType) == 1)
				{
					cin >> inDNA;
DNA_menu:			cout << "Please choose an operation to perform:\n"
						 << "\t1- Convert to RNA.\n"
						 << "\t2- Save DNA to File.\n"
						 << "\t3- Add to another DNA.\n"
						 << "\t4- Check if this DNA Equal to another DNA.\n"
						 << "\t5- Check if this DNA not Equal to another DNA.\n"
						 << "\t6- Go to Main Menu.\n"
						 << "\t(-1)- Exit.\n";
					string operation;
					cin >> operation;
					if (stoi(operation) == 1)
					{
						RNA newRNA = inDNA.ConvertToRNA();
						goto RNA_menu;
					}
					else if (stoi(operation) == 2)
					{
						cout << "Please Choose the file name: ";
						string fName;
						cin >> fName;
						fName += ".txt";
						inDNA.SaveSequenceToFile(fName);
						goto DNA_menu;
					}
					else if (stoi(operation) == 3)
					{
						DNA rhs;
						cin >> rhs;
						DNA sum = (inDNA + rhs);
						cout << sum << endl;
						cout << "You want to work on :"
							 << "\t1- sum\n"
							 << "\t2- old DNA\n"
							 << "\t3- new DNA\n";
						int D;
						cin >> D;
						if (D == 1)
						{
							inDNA = sum;
						}
						else if (D == 3)
						{
							inDNA = rhs;
						}
						goto DNA_menu;
					}
					else if (stoi(operation) == 4)
					{
						DNA rhs;
						cin >> rhs;
						cout << (inDNA == rhs) ? "Equal\n" : "Not Equal\n";
						goto DNA_menu;
					}
					else if (stoi(operation) == 5)
					{
						DNA rhs;
						cin >> rhs;
						cout << (inDNA != rhs) ? "Not Equal\n" : "Equal\n";
						goto DNA_menu;
					}
					else if (stoi(operation) == 6)
					{
						goto main_menu;
					}
					else if (stoi(operation) == -1)
					{
						break;
					}
				}
				else if (stoi(seqType) == 2)
				{
					cin >> inRNA;
RNA_menu:			cout << "Please choose an operation to perform:\n"
						 << "\t1- Convert to DNA.\n"
						 << "\t2- Convert to Protein.\n"
						 << "\t3- Save RNA to File.\n"
						 << "\t4- Add to another RNA.\n"
						 << "\t5- Check if this RNA Equal to another RNA.\n"
						 << "\t6- Check if this RNA not Equal to another RNA.\n"
						 << "\t7- Go to Main Menu.\n"
						 << "\t(-1)- Exit.\n";
					string operation;
					cin >> operation;
					if (stoi(operation) == 1)
					{
						DNA newDNA = inRNA.ConvertToDNA();
						goto DNA_menu;
					}
					else if (stoi(operation) == 2)
					{
						CodonsTable cdn = CodonsTable();
						Protein newProtein = inRNA.ConvertToProtein(cdn);
						goto Protein_menu;
					}
					else if (stoi(operation) == 3)
					{
						cout << "Please Choose the file name: ";
						string fName;
						cin >> fName;
						fName += ".txt";
						inRNA.SaveSequenceToFile(fName);
						goto RNA_menu;
					}
					else if (stoi(operation) == 4)
					{
						RNA rhs;
						cin >> rhs;
						RNA sum = (inRNA + rhs);
						cout << sum << endl;
						cout << "You want to work on :"
							 << "\t1- sum\n"
							 << "\t2- old RNA\n"
							 << "\t3- new RNA\n";
						int D;
						cin >> D;
						if (D == 1)
						{
							inRNA = sum;
						}
						else if (D == 3)
						{
							inRNA = rhs;
						}
						goto RNA_menu;
					}
					else if (stoi(operation) == 5)
					{
						RNA rhs;
						cin >> rhs;
						cout << (inRNA == rhs) ? "Equal\n" : "Not Equal\n";
						goto RNA_menu;
					}
					else if (stoi(operation) == 6)
					{
						RNA rhs;
						cin >> rhs;
						cout << (inRNA != rhs) ? "Not Equal\n" : "Equal\n";
						goto RNA_menu;
					}
					else if (stoi(operation) == 7)
					{
						goto main_menu;
					}
					else if (stoi(operation) == -1)
					{
						break;
					}
				}
				else if (stoi(seqType) == 3)
				{
					cin >> inProtein;
Protein_menu:		cout << "Please choose an operation to perform:\n"
						 << "\t1- Get DNA strands encoding me.\n"
						 << "\t2- Save Protein to File.\n"
						 << "\t3- Add to another Protein.\n"
						 << "\t4- Check if this Protein Equal to another Protein.\n"
						 << "\t5- Check if this Protein not Equal to another Protein.\n"
						 << "\t6- Go to Main Menu.\n"
						 << "\t(-1)- Exit.\n";
					string operation;
					cin >> operation;
					if (stoi(operation) == 1)
					{
						DNA bigDNA;
						cout << "Enter the big DNA: ";
						cin >> bigDNA;
						int DNACount;
						DNA* DNAEncodingMe = inProtein.GetDNAStrandsEncodingMe(bigDNA, DNACount);
						for (int i = 0; i < DNACount; i++)
						{
							cout << "DNA " << (i+1) << ":\n";
							cout << DNAEncodingMe[i];
							cout << endl;
						}
						goto Protein_menu;
					}
					else if (stoi(operation) == 2)
					{
						CodonsTable cdn = CodonsTable();
						Protein newProtein = inRNA.ConvertToProtein(cdn);
						goto Protein_menu;
					}
					else if (stoi(operation) == 3)
					{
						cout << "Please Choose the file name: ";
						string fName;
						cin >> fName;
						fName += ".txt";
						inProtein.SaveSequenceToFile(fName);
						goto Protein_menu;
					}
					else if (stoi(operation) == 4)
					{
						Protein rhs;
						cin >> rhs;
						Protein sum = (inProtein + rhs);
						cout << sum << endl;
						cout << "You want to work on :"
							 << "\t1- sum\n"
							 << "\t2- old RNA\n"
							 << "\t3- new RNA\n";
						int D;
						cin >> D;
						if (D == 1)
						{
							inProtein = sum;
						}
						else if (D == 3)
						{
							inProtein = rhs;
						}
						goto Protein_menu;
					}
					else if (stoi(operation) == 5)
					{
						Protein rhs;
						cin >> rhs;
						cout << (inProtein == rhs) ? "Equal\n" : "Not Equal\n";
						goto Protein_menu;
					}
					else if (stoi(operation) == 6)
					{
						Protein rhs;
						cin >> rhs;
						cout << (inProtein != rhs) ? "Not Equal\n" : "Equal\n";
						goto Protein_menu;
					}
					else if (stoi(operation) == 7)
					{
						goto main_menu;
					}
					else if (stoi(operation) == -1)
					{
						break;
					}
				}
			}
			else if (stoi(choice) == 2)
			{
				cout << "Please choose type of Sequence you want to input:\n"
					 << "\t1- DNA.\n"
					 << "\t2- RNA.\n"
					 << "\t3- Protein.\n";
				string seqType;
				cin >> seqType;
				if (stoi(seqType) == 1)
				{
					//string DNAF;
					cout << "Enter the file name that contains the DNA: ";
					cin >> DNAF;
					DNAF += ".txt";
					inDNA.LoadSequenceFromFile(DNAF);
DNA_menuL:			cout << "Please choose an operation to perform:\n"
						 << "\t1- Convert to RNA.\n"
						 << "\t2- Save DNA to File.\n"
						 << "\t3- Add to another DNA.\n"
						 << "\t4- Check if this DNA Equal to another DNA.\n"
						 << "\t5- Check if this DNA not Equal to another DNA.\n"
						 << "\t6- Go to Main Menu.\n"
						 << "\t(-1)- Exit.\n";
					string operation;
					cin >> operation;
					if (stoi(operation) == 1)
					{
						RNA newRNA = inDNA.ConvertToRNA();
						goto RNA_menuL;
					}
					else if (stoi(operation) == 2)
					{
						cout << "Please Choose the file name: ";
						string fName;
						cin >> fName;
						fName += ".txt";
						inDNA.SaveSequenceToFile(fName);
						goto DNA_menuL;
					}
					else if (stoi(operation) == 3)
					{
						DNA rhs;
						cin >> rhs;
						DNA sum = (inDNA + rhs);
						cout << sum << endl;
						cout << "You want to work on :"
							 << "\t1- sum\n"
							 << "\t2- old DNA\n"
							 << "\t3- new DNA\n";
						int D;
						cin >> D;
						if (D == 1)
						{
							inDNA = sum;
						}
						else if (D == 3)
						{
							inDNA = rhs;
						}
						goto DNA_menuL;
					}
					else if (stoi(operation) == 4)
					{
						DNA rhs;
						cin >> rhs;
						cout << (inDNA == rhs) ? "Equal\n" : "Not Equal\n";
						goto DNA_menuL;
					}
					else if (stoi(operation) == 5)
					{
						DNA rhs;
						cin >> rhs;
						cout << (inDNA != rhs) ? "Not Equal\n" : "Equal\n";
						goto DNA_menuL;
					}
					else if (stoi(operation) == 6)
					{
						goto main_menu;
					}
					else if (stoi(operation) == -1)
					{
						break;
					}
				}
				else if (stoi(seqType) == 2)
				{
					cout << "Enter the file name that contains the RNA: ";
					cin >> RNAF;
					RNAF += ".txt";
					inRNA.LoadSequenceFromFile(RNAF);
RNA_menuL:			cout << "Please choose an operation to perform:\n"
						 << "\t1- Convert to DNA.\n"
						 << "\t2- Convert to Protein.\n"
						 << "\t3- Save RNA to File.\n"
						 << "\t4- Add to another RNA.\n"
						 << "\t5- Check if this RNA Equal to another RNA.\n"
						 << "\t6- Check if this RNA not Equal to another RNA.\n"
						 << "\t7- Go to Main Menu.\n"
						 << "\t(-1)- Exit.\n";
					string operation;
					cin >> operation;
					if (stoi(operation) == 1)
					{
						DNA newDNA = inRNA.ConvertToDNA();
						goto DNA_menuL;
					}
					else if (stoi(operation) == 2)
					{
						CodonsTable cdn = CodonsTable();
						Protein newProtein = inRNA.ConvertToProtein(cdn);
						goto Protein_menuL;
					}
					else if (stoi(operation) == 3)
					{
						cout << "Please Choose the file name: ";
						string fName;
						cin >> fName;
						fName += ".txt";
						inRNA.SaveSequenceToFile(fName);
						goto RNA_menuL;
					}
					else if (stoi(operation) == 4)
					{
						RNA rhs;
						cin >> rhs;
						RNA sum = (inRNA + rhs);
						cout << sum << endl;
						cout << "You want to work on :"
							 << "\t1- sum\n"
							 << "\t2- old RNA\n"
							 << "\t3- new RNA\n";
						int D;
						cin >> D;
						if (D == 1)
						{
							inRNA = sum;
						}
						else if (D == 3)
						{
							inRNA = rhs;
						}
						goto RNA_menuL;
					}
					else if (stoi(operation) == 5)
					{
						RNA rhs;
						cin >> rhs;
						cout << (inRNA == rhs) ? "Equal\n" : "Not Equal\n";
						goto RNA_menuL;
					}
					else if (stoi(operation) == 6)
					{
						RNA rhs;
						cin >> rhs;
						cout << (inRNA != rhs) ? "Not Equal\n" : "Equal\n";
						goto RNA_menuL;
					}
					else if (stoi(operation) == 7)
					{
						goto main_menu;
					}
					else if (stoi(operation) == -1)
					{
						break;
					}
				}
				else if (stoi(seqType) == 3)
				{
					//string ProteinF;
					cout << "Enter the file name that contains the RNA: ";
					cin >> ProteinF;
					ProteinF += ".txt";
					inProtein.LoadSequenceFromFile(ProteinF);
Protein_menuL:		cout << "Please choose an operation to perform:\n"
						 << "\t1- Get DNA strands encoding me.\n"
						 << "\t2- Save Protein to File.\n"
						 << "\t3- Add to another Protein.\n"
						 << "\t4- Check if this Protein Equal to another Protein.\n"
						 << "\t5- Check if this Protein not Equal to another Protein.\n"
						 << "\t6- Go to Main Menu.\n"
						 << "\t(-1)- Exit.\n";
					string operation;
					cin >> operation;
					if (stoi(operation) == 1)
					{
						DNA bigDNA;
						cout << "Enter the big DNA: ";
						cin >> bigDNA;
						int DNACount;
						DNA* DNAEncodingMe = inProtein.GetDNAStrandsEncodingMe(bigDNA, DNACount);
						for (int i = 0; i < DNACount; i++)
						{
							cout << "DNA " << (i+1) << ":\n";
							cout << DNAEncodingMe[i];
							cout << endl;
						}
						goto Protein_menuL;
					}
					else if (stoi(operation) == 2)
					{
						cout << "Please Choose the file name: ";
						string fName;
						cin >> fName;
						fName += ".txt";
						inProtein.SaveSequenceToFile(fName);
						goto Protein_menuL;
					}
					else if (stoi(operation) == 3)
					{
						Protein rhs;
						cin >> rhs;
						Protein sum = (inProtein + rhs);
						cout << sum << endl;
						cout << "You want to work on :"
							 << "\t1- sum\n"
							 << "\t2- old RNA\n"
							 << "\t3- new RNA\n";
						int D;
						cin >> D;
						if (D == 1)
						{
							inProtein = sum;
						}
						else if (D == 3)
						{
							inProtein = rhs;
						}
						goto Protein_menuL;
					}
					else if (stoi(operation) == 4)
					{
						Protein rhs;
						cin >> rhs;
						cout << (inProtein == rhs) ? "Equal\n" : "Not Equal\n";
						goto Protein_menuL;
					}
					else if (stoi(operation) == 5)
					{
						Protein rhs;
						cin >> rhs;
						cout << (inProtein != rhs) ? "Not Equal\n" : "Equal\n";
						goto Protein_menuL;
					}
					else if (stoi(operation) == 6)
					{
						goto main_menu;
					}
					else if (stoi(operation) == -1)
					{
						break;
					}
				}
			}
		}
		catch (...)
		{
			cout << "Error! Invalid choice. Please try again!\n";
		}
	}
	system("pause");
    return 0;
}