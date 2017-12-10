#pragma once
#include <iostream>
#include <fstream>

#define MAX_SIZE_OF_SynapsMatrix  300
class SynapsMatrix
{
private:
	double **weight;
	int NumberOfMatrix;
public:
	SynapsMatrix();
	void SetNumberOfMatrix(int Number);
	int GetNumberOfMatrix();
	void SetWeightOfMatrix(int width, int length, double InputtedWeight);
	void SetWeightOfSynapse(int i, int j, double InputtedWeight);
	double GetWeightOfSynapse(int i, int j);
	void OutputSynapsMatrix(int width, int length);
	void SetMatrixInMemory(int width, int length);
	void GetMatrixFromMemory(int width, int length);
	~SynapsMatrix();
};

