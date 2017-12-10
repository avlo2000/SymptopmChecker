#include<vector>
#include<string>
#include<iostream>
#pragma once

using namespace std;
const int MAX_SIZE_OF_INPUT = 60;
const int MAX_SIZE_OF_OUTPUT = 600;

class TrainingSetStr
{
private:
	string *input_list = new string[MAX_SIZE_OF_INPUT];
	string *output_list = new string[MAX_SIZE_OF_OUTPUT];
	double *input = new double[MAX_SIZE_OF_INPUT];
	double *output = new double[MAX_SIZE_OF_OUTPUT];
	int size_of_input;
	int size_of_output;
public:
	TrainingSetStr(string *input_untransformed, string *output_untransformed, int size_of_input, int size_of_output);
	void TransformIntoSet(vector<string> input, vector<string> output);
	double* GetInput();
	double* GetOutput();
	void ShowTrainigSet();
	~TrainingSetStr();
};

