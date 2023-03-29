#include"functions.h"


// Random text generator 
char CharRand()
{
	static unsigned char seed = 124;
	seed = (8253729 * seed + 2396403);
	if ('0' <= seed % 255 && seed % 255 <= '9') return seed;
	if ('a' <= seed % 255 && seed % 255 <= 'z') return seed;
	if ('A' <= seed % 255 && seed % 255 <= 'Z') return seed;
	CharRand();
}

char* RandWordGen(int wordSize)
{
	char* word = (char*)malloc(sizeof(char) * (wordSize + 1));
	for (int i = 0; i < wordSize; i++)
	{
		word[i] = CharRand();
	}
	word[wordSize] = '\0';
	return word;
}


// String - not used yet
void StrEntry(char* ic, const char* oc)
{
	int nic = StrSize(ic);
	int noc = ConstStrSize(oc);
	for (int i = 0; i < (nic < noc ? nic : noc); i++)
	{
		ic[i] = oc[i];
	}
	ic[(nic < noc ? nic : noc) - 1] = '\0';
	return;
}

int StrSize(char* str)
{
	for (int i = 0; i < 1000; i++)
	{
		if (str[i] == '\0') return i + 1;
	}
	cout << "StrSize Error Message!" << endl;
	return 0;
}

int ConstStrSize(const char* str)
{
	for (int i = 0; i < 1000; i++)
	{
		if (str[i] == '\0') return i + 1;
	}
	cout << "ConstStrSize Error Message!" << endl;
	return 0;
}


// Work with files
void AutoEntryEmptyFile(const char* filename)
{
	ofstream os(filename);

	if (!os)
	{
		cout << "AutoEntryEmptyFile Error!" << endl;
		return;
	}

	char* word;

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			word = RandWordGen(8);
			os << word << ';';
			free(word);
		}
		os << endl;
	}

	os.close();
	return;
}
