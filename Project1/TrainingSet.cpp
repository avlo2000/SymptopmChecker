#include "TrainingSet.h"



TrainingSetStr::TrainingSetStr(string *input_list, string *output_list, int size_of_input, int size_of_output)
{
	this->input_list = input_list;
	this->output_list = output_list;
	this->size_of_input = size_of_input;
	this->size_of_output = size_of_output;
}

void TrainingSetStr::TransformIntoSet(vector<string> input, vector<string> output)
{
	for (int i = 0; i < size_of_input; i++)
	{
		this->input[i] = 0;
	}
	for (int i = 0; i < size_of_output; i++)
	{
		this->output[i] = 0;
	}
	for (int i = 0; i < size_of_input; i++)
	{
		for (int j = 0; j < input.size(); j++)
		{
			if (input.at(j) == input_list[i])
			{
				this->input[i] = 1;
			}
		}
	}
	for (int i = 0; i < size_of_output; i++)
	{
		for (int j = 0; j < output.size(); j++)
		{
			if (output.at(j) == output_list[i])
			{
				this->output[i] = 1;
			}
		}
	}
}

double* TrainingSetStr::GetInput()
{
	return input;
}

double* TrainingSetStr::GetOutput()
{
	return output;
}

void TrainingSetStr::ShowTrainigSet()
{
	cout << "Input:" << endl;
	for (int i = 0; i < size_of_input; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	cout << "Output:" << endl;
	for (int i = 0; i < size_of_output; i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}

TrainingSetStr::~TrainingSetStr()
{
	delete(input);
	delete(output);
}
