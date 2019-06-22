#include <iostream>

using namespace std;

class DNA
{
private:
	//File being analyzed
	string filename = "";
	//Whether input file is valid
	bool isValid = true;
	//Whether this is the first time a file is being analyed
	bool isFirst;
	//Number of total nucleotides
	int sum = 0;
	//Average length per line
	double mean = 0;
	//Variance of length
	double variance = 0;
	//Standard deviation of length
	double stdDev = 0;
	//Number of each nucleotide in the file
	double numA = 0;
	double numC = 0;
	double numT = 0;
	double numG = 0;
	//Number of bigram pairs in the file
	double numAA = 0;
	double numAC = 0;
	double numAT = 0;
	double numAG = 0;
	double numCA = 0;
	double numCC = 0;
	double numCT = 0;
	double numCG = 0;
	double numTA = 0;
	double numTC = 0;
	double numTT = 0;
	double numTG = 0;
	double numGA = 0;
	double numGC = 0;
	double numGT = 0;
	double numGG = 0;
public:
	//default constructor
	DNA(string file);
	//overloaded constructor
	DNA(string file, bool isFirst);
	void computeStats();
	bool checkLine(string line);
	void outFile();
	void outStats(ofstream& myfile);
	void outDna(ofstream& myfile);
	int getGaussian();
	void calcProbNucleotide(string seq);
	void calcProbBigram(string seq);
};
