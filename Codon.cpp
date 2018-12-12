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
#include "codon.h"
#include <cstring>
#include <fstream>
using namespace std;

    CodonsTable::CodonsTable()
    {
       LoadCodonsFromFile("RNA_codon_table.txt");
    }
    CodonsTable::~CodonsTable()
    {

    }
    // function to load all codons from the given text file
    void CodonsTable::LoadCodonsFromFile(string codonsFileName)
    {
        ifstream cdnFile;
		int n = codonsFileName.length();
        /*char* char_array = new char[n];
        for (int i = 0; i < n; i++)
        {
            char_array[i] = codonsFileName[i];
        }*/

        cdnFile.open(codonsFileName, ios::in);
        char temp[4];
        char AA;
        int counter = 0;
        while (!cdnFile.eof() && counter != 64)
        {
            cdnFile >> temp >> AA;
            codons[counter].value[0] = temp[0];
			codons[counter].value[1] = temp[1];
			codons[counter].value[2] = temp[2];
			codons[counter].value[3] = '\0';
            codons[counter].AminoAcid = AA;
            counter++;
        }
    }
    Codon CodonsTable::getAminoAcid(char * value)
	{
		Codon res;
		res.value[0] = value[0];
		res.value[1] = value[1];
		res.value[2] = value[2];
		for (int i = 0; i < 64; i++)
		{
			if ((res.value[0] == codons[i].value[0]) && (res.value[1] == codons[i].value[1]) && (res.value[2] == codons[i].value[2]))
			{
				res.AminoAcid = codons[i].AminoAcid;
				return res;
			}
		}
	}
	void CodonsTable::setCodon(char * value, char AminoAcid, int index)
	{
		Codon res;
		res.value[0] = value[0];
		res.value[1] = value[1];
		res.value[2] = value[2];
		res.AminoAcid = AminoAcid;
		codons[index] = res;
	}
	
	Codon CodonsTable::getCodon(int index)
	{
		Codon res;
		res.value[0] = codons[index].value[0];
		res.value[1] = codons[index].value[1];
		res.value[2] = codons[index].value[2];
		res.AminoAcid = codons[index].AminoAcid;
		return res;
	}
