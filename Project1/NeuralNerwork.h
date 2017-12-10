#pragma once
#include "LayerOfNeurons.h"
#define MAX_NUMBER_OF_LAYERS 3


using namespace NeuralNet;



class NeuralNerwork
{
private:
	LayerOfNeurons NNet[MAX_NUMBER_OF_LAYERS];
	int NumberOfLayers;
public:
	NeuralNerwork();
	NeuralNerwork(int NumOfLayers, int *sizes);
	void SetNumberOfLayers(int number);
	int GetNumberOfLayers();
	void ReturnNeuralNetFromMemory();
	void RecreateNeuralNet(int NumOfLayers, int *sizes);
	void RunNeuralNet(double *input);
	void GetOutputOfTheLayer(int number);
	int GetSizeOfLayer(int number);
	void ShowNeuralNetwork();
	double GetRootMSE(double* IdealOutput);
	void BackPropagationTeaching(double* TrainingSet, double* IdealOutput, double LearningRate);
	LayerOfNeurons ReturnLayer(int i);
	~NeuralNerwork();
};



