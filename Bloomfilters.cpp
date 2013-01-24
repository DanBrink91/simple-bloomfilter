// Bloomfilters.cpp
// Single hash bloomfilter
#include <iostream>
#include "BitArray.h"
#include <string>
#include <fstream>
using namespace std;

const int PRIME = 179426549;

int main(int argc, char* argv[])
{
	BitArray b = BitArray();
	hash<string> str_hash;
	string in;
	ifstream myfile("words.txt");
	if(myfile.is_open())
	{
		while(myfile.good())
		{
			getline(myfile, in);
			size_t h = str_hash(in) % PRIME;
			b.set(h);
		}
		myfile.close();
	}
	else
	{
		cout << "No file.\n";
	}
	do{
		cout << "Enter string:";
		cin >> in;
		size_t h = str_hash(in) % PRIME;
		if(b.get(h))
		{
			cout << in << " is already member of the set.\n";
		}
		else
		{
			cout << "Not in set.\n";
		}
	}while(in!="exit");
	//system("PAUSE");
	return 0;
}

