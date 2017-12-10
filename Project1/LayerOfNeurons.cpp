#include "LayerOfNeurons.h"



LayerOfNeurons::LayerOfNeurons()
{
}

LayerOfNeurons::LayerOfNeurons(int size)
{
	SizeOfLayer = size;
}

void LayerOfNeurons::SetNumberOfLayer(int number)
{
	NumberOfLayer = number;
}

void LayerOfNeurons::SetSizeOfLayer(int size)
{
	SizeOfLayer = size;
	NeuronOfLayer = new Neuron[size];
}

int LayerOfNeurons::GetSizeOfLayer()
{
	return SizeOfLayer;
}

double LayerOfNeurons::GetOutputOfNeuron(int index)
{
	return NeuronOfLayer[index].GetOutput();
}

void LayerOfNeurons::SetSynapsesForLayer(LayerOfNeurons& PreviousLayer, double StartWeight)
{
	Synapses.SetNumberOfMatrix(NumberOfLayer);
	Synapses.SetWeightOfMatrix(SizeOfLayer, PreviousLayer.SizeOfLayer, StartWeight);
	Synapses.SetMatrixInMemory(SizeOfLayer, PreviousLayer.SizeOfLayer);
}

void LayerOfNeurons::SetSynapsesForLayer(LayerOfNeurons& PreviousLayer)
{
	Synapses.SetNumberOfMatrix(NumberOfLayer);
	Synapses.GetMatrixFromMemory(SizeOfLayer, PreviousLayer.SizeOfLayer);
}

SynapsMatrix LayerOfNeurons::GetSynapsesForLayer()
{
	return Synapses;
}

Neuron LayerOfNeurons::ReturnNeuron(int i)
{
	return NeuronOfLayer[i];
}

void LayerOfNeurons::SetInputOfLayer(LayerOfNeurons& PreviousLayer)
{
	double buffSum;
	for (int i = 0; i < SizeOfLayer; i++)
	{
		buffSum = 0;
		for (int j = 0; j < PreviousLayer.SizeOfLayer; j++)
		{
			buffSum += PreviousLayer.NeuronOfLayer[j].GetOutput() * Synapses.GetWeightOfSynapse(i, j);
			//cout << PreviousLayer.NeuronOfLayer[j].GetOutput() << " * " << Synapses.GetWeightOfSynapse(i, j) << " + "; // For checking calculating of neural network
		}
		//cout << endl;
		NeuronOfLayer[i].SetInput(buffSum);
		NeuronOfLayer[i].SetOutput(NeuronOfLayer[i].GetInput());
	}
}

void LayerOfNeurons::SetInputOfLayer(bool isInputNeurons, double *buffSum)
{
	for (int i = 0; i < SizeOfLayer; i++)
	{
		NeuronOfLayer[i].SetFirstInput(buffSum[i]);
		NeuronOfLayer[i].SetFirstOutput(NeuronOfLayer[i].GetInput());
	}
}

LayerOfNeurons::~LayerOfNeurons()
{
}
