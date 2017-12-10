#include <iostream>
#include "stdNNO.h"
#include <fstream>
#include <conio.h>

using namespace std;
using namespace NeuralNet;

void test(int NumOfLayers, int* sizes)
{
	NeuralNerwork a(NumOfLayers, sizes);
	double *input = new double[a.GetSizeOfLayer(1)];
	double *output = new double[a.GetSizeOfLayer(a.GetNumberOfLayers())];
	for (int epoch = 0; epoch < 1000; epoch++)
	{
		cout << "           ...Training epoch number " << epoch + 1 << "...           " << endl;
		for (int set = 0; set < 10; set++)
		{
			for (int i = 0; i < a.GetSizeOfLayer(1); i++)
			{
				input[i] = 0;
			}
			input[set] = 1;
			for (int i = 0; i < a.GetSizeOfLayer(a.GetNumberOfLayers()); i++)
			{
				output[i] = 0;
			}
			output[set] = 0.5;
			/*if (set != 9)
			{
				input[set + 1] = 1;
			}
			else
			{
				input[0] = 1;
			}
			if (set != 0)
			{
				input[set - 1] = 1;
			}
			else
			{
				input[9] = 1;
			}*/
			if (set != 9)
			{
				output[set + 1] = 1;
			}
			else
			{
				output[0] = 1;
			}
			cout << "Input: " << endl;
			for (int i = 0; i < a.GetSizeOfLayer(1); i++)
				cout << input[i];
			cout << endl;
			cout << "Output: " << endl;
			for (int i = 0; i < a.GetSizeOfLayer(1); i++)
				cout << output[i];
			cout << endl;
			a.BackPropagationTeaching(input, output, 10);
			a.GetOutputOfTheLayer(a.GetNumberOfLayers());
			cout << "Root MSE: " << a.GetRootMSE(output) << endl << endl << endl << endl;
			
		}
		system("pause");
	}
	for (int i = 0; i < 2; i++) {
		for (int set = 0; set < 10; set++)
		{
			cin >> input[set];
		}
		a.RunNeuralNet(input);
		a.GetOutputOfTheLayer(a.GetNumberOfLayers());
		system("pause");
	}
}         

void GetTrainingSet(string *input, string *output , int index)
{
	string file_lacation = "D:\\PythonProjects\\sample_for_hc\\";
	ifstream fin;
	string file_name = "training_set";
	char buff[100];
	fin.open(file_lacation + file_name + to_string(index) + ".txt");
	//cout << file_lacation + file_name + to_string(index) + ".txt" << endl;
	fin.getline(buff, 100);

	fin.close();
}

void GetInOut(string *all_in, string *all_out)
{
	string file_lacation = "D:\\PythonProjects\\sample_for_hc\\";
	ifstream fin;
	fin.open(file_lacation + "all_symptoms.txt");
	int size;
	fin >> size;
	char buff[100];
	for (int i = 0; i < size; i++)
	{
		fin.getline(buff, 200);
		all_in[i] = buff;
	}
	fin.close();

	fin.open(file_lacation + "all_diseases.txt");
	fin >> size;
	for (int i = 0; i < size; i++)
	{
		fin.getline(buff, 200);
		all_out[i] = buff;
	}
	fin.close();
}

int main()
{

    int NumOfLayers;
	cout << "Input number of layers:" << endl;
	cin >> NumOfLayers;
	int *sizes = new int[NumOfLayers];
	for (int i = 0; i < NumOfLayers; i++)
	{
		cout << "Input size of layer " << i + 1 << ": " << endl;
		cin >> sizes[i];
	}
	//NeuralNerwork SympChecker(NumOfLayers, sizes);
	string *all_symptoms = new string[sizes[0]];
	string *all_diseases = new string[sizes[NumOfLayers - 1]];
	double *input = new double[sizes[0]];
	double *output = new double[sizes[NumOfLayers - 1]];
	GetInOut(all_symptoms, all_diseases);
	TrainingSetStr tr_set(all_symptoms, all_diseases, sizes[0], sizes[NumOfLayers - 1]);

	system("pause");
	return 0;
}