#include "SynapsMatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

SynapsMatrix::SynapsMatrix()
{
	NumberOfMatrix = 0;
}

void SynapsMatrix::SetNumberOfMatrix(int Number)
{
	NumberOfMatrix = Number;
};

int SynapsMatrix::GetNumberOfMatrix()
{
	return NumberOfMatrix;
};

void SynapsMatrix::SetWeightOfMatrix(int width, int length, double InputtedWeight)
{
	weight = new double*[width];
	for (int i = 0; i < width; ++i)
	{
		weight[i] = new double[length];
		for (int j = 0; j < length; ++j)
		{
			//cout << "Input weight of synaps:" << endl; // For checking calculating of neural network
			//cin >> InputtedWeight;

			InputtedWeight = rand() % 1000000;
			weight[i][j] = InputtedWeight / 1000000;
		};
	}
};

void SynapsMatrix::SetWeightOfSynapse(int i, int j, double InputtedWeight)
{
	weight[i][j] = InputtedWeight;
};

double SynapsMatrix::GetWeightOfSynapse(int i, int j)
{
	return weight[i][j];
};

void SynapsMatrix::OutputSynapsMatrix(int width, int length)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			std::cout << weight[i][j] << "  ";
		}
		std::cout << std::endl;
	}
};

void SynapsMatrix::SetMatrixInMemory(int width, int length)
{
	string NameOfFile = "SynapseMatrix";
	string NumberOfFile;
	if (NumberOfMatrix < 10)
	{
		NameOfFile += (char)(NumberOfMatrix + 48);
	}
	else
	{
		int buff1 = NumberOfMatrix;
		int buff2 = NumberOfMatrix % 10;
		buff1 = (NumberOfMatrix - buff2) / 10;
		NameOfFile += (char)(buff1 + 48);
		NameOfFile += (char)(buff2 + 48);

	}
	NameOfFile += ".txt";
	ofstream fout(NameOfFile, ios_base::out | ios_base::trunc);
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			fout << weight[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

void SynapsMatrix::GetMatrixFromMemory(int width, int length)
{
	string NameOfFile = "SynapseMatrix";
	string NumberOfFile;
	if (NumberOfMatrix < 10)
	{
		NameOfFile += (char)(NumberOfMatrix + 48);
	}
	else
	{
		int buff1 = NumberOfMatrix;
		int buff2 = NumberOfMatrix % 10;
		buff1 = (NumberOfMatrix - buff2) / 10;
		NameOfFile += (char)(buff1 + 48);
		NameOfFile += (char)(buff2 + 48);

	}
	NameOfFile += ".txt";
	ifstream fin(NameOfFile, ios_base::in);
	weight = new double*[width];
	for (int i = 0; i < width; ++i)
	{
		weight[i] = new double[length];
		for (int j = 0; j < length; ++j)
		{
			fin >> weight[i][j];
		}
	}
	fin.close();
}

SynapsMatrix::~SynapsMatrix()
{
}
