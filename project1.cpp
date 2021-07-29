#include<iostream>
#include <string>
using namespace std;

class DNA
{
protected:
	char** subStrings;
	int numSubStrings;
	int subStringLen;
public:
	DNA();
	DNA(int n, int k);
	void makeSubStrings(char* s);
	void findOverlap(int o);
	char* sequenceGenerator(int n, unsigned int seed);
	static char DNAbases[4];
};

/* Initializing static array variable*/
char DNA::DNAbases[4] = { 'A', 'C', 'T', 'G' };

/*Default constructor*/
DNA::DNA() {

	numSubStrings = 0;
	subStringLen = 0;
	subStrings[numSubStrings][subStringLen] = {};
}

/*Non default constructor*/
DNA::DNA(int n, int k) {

	numSubStrings = n/k;
	subStringLen = k;
	subStrings = new char* [numSubStrings];

	for (int i = 0; i < numSubStrings; i++) 
	{		
		char* temp = new char[subStringLen + 1];
		temp[subStringLen] = 0;
		subStrings[i] = temp;
	}
}

void DNA::makeSubStrings(char* sequence)
{
	static int n = 0; /*Static counter variable for sequence  */

	for (int i = 0; i < numSubStrings; i++)
	{
		for (int m = 0; m < subStringLen; m++) {
			subStrings[i][m] = sequence[n];
			n = n + 1;
		}
	}
	cout << "Substrings of length " << subStringLen <<":"<< endl;

	/* Creating Substrings */

	for (int i = 0; i < numSubStrings; i++)
	{
		string s = "";
		for (int j = 0; j < subStringLen; j++)
		{
			s = s + subStrings[i][j];
		}
		cout << i << ": " << "" << s << endl;
	}
	
}
/* Function to identify matches in the substrings*/

void DNA::findOverlap(int o)
{
	cout << "Matches found:" << endl;

	for (int i = 0; i < numSubStrings; i++)
	{
		for (int c = 0; c <= subStringLen - o; c++)
		{
			for (int j = i+1; j < numSubStrings; j++)
			{
				for (int z = 0; z <= subStringLen; z++)
				{
					if (i != j)
					{
						int count = 0;
						int h = c;
						int y = z;
						count = 0;
						for (int m = 0; m < o; m++)
						{
							if (subStrings[i][h] != subStrings[j][y])
							{
								break;
							}
							if (subStrings[i][h] == subStrings[j][y])
							{
								count = count + 1;
							}
							h = h + 1;
							y = y + 1;
							if (count == o)
							{
								cout << i << " " << j << endl;
								break;
							}
						}
					}
				}
			}
		}
	}

}

/*Sequence Generation*/
char* DNA::sequenceGenerator(int n, unsigned int seed)
{
	char* sequence = new char[n];
	sequence[n] = '\0';
	srand(seed);
	for (int i = 0; i < n; i++) {

		int random_number = rand() % 4;
		sequence[i] = DNAbases[random_number];
	}

	return sequence;
}


int main()
{

	int n, k, o, seed;
	cin >> n >> seed >> k >> o;

	DNA Dna_Object = DNA(n, k); /*Default constructor invoke*/
	char* sequence = Dna_Object.sequenceGenerator(n, seed); /* Generating sequence*/
	Dna_Object.makeSubStrings(sequence); /*Creating Substrings for the sequence*/
	Dna_Object.findOverlap(o);	 /* Finding the matches for the substrings created*/

	return 0;
}

