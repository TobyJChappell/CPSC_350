#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "DNA.h"

using namespace std;

/**
Default constructor for DNA (used if user does not want to append results)
@param file The name of the file that is being analyzed
*/
DNA::DNA(string file)
{
	filename = file;
	isFirst = true;
}

/**
Overloaded constructor for DNA (used if user wants to append results)
@param file The name of the file that is being analyzed
@param first Whether this is the first time a file is being inputted
*/
DNA::DNA(string file, bool first)
{
	filename = file;
	isFirst = first;
}

/**
Computes and updates the sum, mean, variance, and standard deviation of a file
*/
void DNA::computeStats()
{
	cout << endl;
	cout << "Analyzing the file..." << endl;
	string line = "";
	ifstream file(filename);
	int numLines = 0;
	if(file.is_open())
  {
    while(getline(file, line))
    {
			if(checkLine(line))
			{
				sum += line.size();
				numLines++;
				calcProbNucleotide(line);
				calcProbBigram(line);
			}
    }
		mean = (double)sum/numLines;
		file.clear();
		file.seekg(0, file.beg);
		while(getline(file, line))
		{
			if(checkLine(line))
			{
				variance += pow((line.size() - mean), 2);
			}
		}
		variance /= numLines;
		stdDev = sqrt(variance);
		file.close();
	}
	if(numLines == 0)
	{
		isValid = false;
		cout << "ERROR: Invalid file input!" << endl;
		cout << endl;
	}
	else
	{
		cout << "File analyzed." << endl;
	}
}

/**
Determines if a line is valid (has an even length and contains only the letters a, c , t, or g)
@param line A single dna strand
@return bool True if the line is valid
*/
bool DNA::checkLine(string line)
{
	if(line.size() % 2 == 1 || line.size() == 0)
	{
		return false;
	}
	for(int x = 0; x < line.size(); x++)
	{
		char temp = toupper(line[x]);
		if(temp != 'A' && temp != 'C' && temp != 'T' && temp != 'G')
		{
			return false;
		}
	}
	return true;
}

/**
Outputs the name, student_id, etc., statistics, and 1000 dna strands to a file
*/
void DNA::outFile()
{
	if(isValid)
	{
		cout << "Outputting file..." << endl;
		ofstream file;
		if(isFirst)
		{
			file.open("tobychappell.out");
			file << "@name Toby Chappell" << endl;
			file << "@student_id 2312642" << endl;
			file << "@email tchappell@chapman.edu" << endl;
			file << "@course CPSC-350-02" << endl;
			file << "@assignment 1" << endl;
			file << endl;
		}
		else
		{
			file.open("tobychappell.out", ios_base::app);
			file << endl;
		}
	  if(file.is_open())
	  {
			outStats(file);
			outDna(file);
	    file.close();
			cout << "File outputted to \"tobychappell.out\"" << endl;
			cout << endl;
	  }
	}
}

/**
Outputs the statistics conducted on a file of dna strands
@param ofstream& The file that the strings are being outputted to
*/
void DNA::outStats(ofstream& file)
{
	file << "Sum: " << sum << endl;
	file << "Mean: " << mean << endl;
	file << "Variance: " << variance << endl;
	file << "Standard Deviation: " << stdDev << endl;
	file << endl;
	file << "Probability of each nucleotide:" << endl;
	file << "Percent A: " << (numA/sum)*100 << "%" << endl;
	file << "Percent C: " << (numC/sum)*100 << "%" << endl;
	file << "Percent T: " << (numT/sum)*100 << "%" << endl;
	file << "Percent G: " << (numG/sum)*100 << "%" << endl;
	file << endl;
	file << "Probability of each bigram:" << endl;
	file << "Percent AA: " << numAA/sum*200 << "%" << endl;
	file << "Percent AC: " << numAC/sum*200 << "%" << endl;
	file << "Percent AT: " << numAT/sum*200 << "%" << endl;
	file << "Percent AG: " << numAG/sum*200 << "%" << endl;
	file << "Percent CA: " << numCA/sum*200 << "%" << endl;
	file << "Percent CC: " << numCC/sum*200 << "%" << endl;
	file << "Percent CT: " << numCT/sum*200 << "%" << endl;
	file << "Percent CG: " << numCG/sum*200 << "%" << endl;
	file << "Percent TA: " << numTA/sum*200 << "%" << endl;
	file << "Percent TC: " << numTC/sum*200 << "%" << endl;
	file << "Percent TT: " << numTT/sum*200 << "%" << endl;
	file << "Percent TG: " << numTG/sum*200 << "%" << endl;
	file << "Percent GA: " << numGA/sum*200 << "%" << endl;
	file << "Percent GC: " << numGC/sum*200 << "%" << endl;
	file << "Percent GT: " << numGT/sum*200 << "%" << endl;
	file << "Percent GG: " << numGG/sum*200 << "%" << endl;
	file << endl;
}

/**
Outputs 1000 DNA strings following Gaussian distribution to a file
@param ofstream& The file that the strings are being outputted to
*/
void DNA::outDna(ofstream& file)
{
	int D;
	for(int x = 0; x < 1000; x++)
	{
		D = getGaussian();
		for(int y = 0; y < D; y++)
		{
			double r = ((double) rand() / (RAND_MAX));
			if(r < numA/sum)
			{
				file << 'A';
			}
			else if(r < (numA+numC)/sum)
			{
				file << 'C';
			}
			else if(r < (numA + numC + numT)/sum)
			{
				file << 'T';
			}
			else
			{
				file << 'G';
			}
		}
		file << endl;
	}
}

/**
Generates a random number following Gaussian distribution (if number is odd, a 1 is added since DNA strands cannot have odd lengths)
@return Gaussian number
*/
int DNA::getGaussian()
{
	double a, b, C;
	int D;
	do
	{
		a = ((double) rand() / (RAND_MAX));
		b = ((double) rand() / (RAND_MAX));
		C = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
		D = stdDev * C + mean;
	} while(D < 1);
	if(D % 2 == 1)
	{
		D++;
	}
	return D;
}

/**
Updates the totals of each nucleotide in a string
@param seq A signle dna string
*/
void DNA::calcProbNucleotide(string seq)
{
	for(int x = 0; x < seq.size(); x++)
	{
		char temp = toupper(seq[x]);
		if(temp == 'A')
		{
			numA++;
		}
		else if(temp == 'C')
		{
			numC++;
		}
		else if(temp == 'T')
		{
			numT++;
		}
		else if(temp == 'G')
		{
			numG++;
		}
	}
}

/**
Updates the totals of each bigram pair in a string
@param seq A signle dna string
*/
void DNA::calcProbBigram(string seq)
{
	for(int x = 0; x < seq.size(); x+=2)
	{
		char temp = toupper(seq[x]);
		char temp2 = toupper(seq[x + 1]);
		if(temp == 'A')
		{
			if(temp2 == 'A')
			{
				numAA++;
			}
			else if(temp2 == 'C')
			{
				numAC++;
			}
			else if(temp2 == 'T')
			{
				numAT++;
			}
			else if(temp2 == 'G')
			{
				numAG++;
			}
		}
		else if(temp == 'C')
		{
			if(temp2 == 'A')
			{
				numCA++;
			}
			else if(temp2 == 'C')
			{
				numCC++;
			}
			else if(temp2 == 'T')
			{
				numCT++;
			}
			else if(temp2 == 'G')
			{
				numCG++;
			}
		}
		else if(temp == 'T')
		{
			if(temp2 == 'A')
			{
				numTA++;
			}
			else if(temp2 == 'C')
			{
				numTC++;
			}
			else if(temp2 == 'T')
			{
				numTT++;
			}
			else if(temp2 == 'G')
			{
				numTG++;
			}
		}
		else if(temp == 'G')
		{
			if(temp2 == 'A')
			{
				numGA++;
			}
			else if(temp2 == 'C')
			{
				numGC++;
			}
			else if(temp2 == 'T')
			{
				numGT++;
			}
			else if(temp2 == 'G')
			{
				numGG++;
			}
		}
	}
}
