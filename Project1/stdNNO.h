#pragma once
#include "NeuralNerwork.h"
#include "TrainingSet.h"

using namespace std;
namespace NeuralNet 
{
	void TeachNeuralNetwork(NeuralNerwork Network, double* TrainingSet, double* IdealOutput, double LearningRate)
	{
		Network.RunNeuralNet(TrainingSet);
		double buffer;
		double error;
		for (int i = Network.GetNumberOfLayers() - 1; i > 0; i--)
		{
			for (int index1 = 0; index1 < Network.GetSizeOfLayer(i); index1++)
			{
				for (int index2 = 0; index2 < Network.GetSizeOfLayer(i - 1); index2++)
				{
					if (i == Network.GetNumberOfLayers() - 1)
					{
						buffer = Network.ReturnLayer(i - 1).GetOutputOfNeuron(index2)*Network.ReturnLayer(i).ReturnNeuron(index2).GetDelta(IdealOutput[index1])*LearningRate;
						Network.ReturnLayer(i).GetSynapsesForLayer().SetWeightOfSynapse(index1, index2, Network.ReturnLayer(i).GetSynapsesForLayer().GetWeightOfSynapse(index1, index2) - buffer);
					}
					else
					{
						error = 1;
						//for (int k = 0; k < )
						//error = Network.ReturnLayer(i).GetSynapsesForLayer().GetWeightOfSynapse(index1, index2)*Network.ReturnLayer(i-1).ReturnNeuron(index1).GetDelta(IdealOutput[index1]);
						//TO DO SMTH...
					}
				}
			}
		}
	}
}