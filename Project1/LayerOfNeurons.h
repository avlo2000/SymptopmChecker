#pragma once
#include "Neuron.h"
using namespace NeuralNet;
#define MAX_SIZE_OF_LAYER  300
class LayerOfNeurons
{
private:
	int NumberOfLayer;
	int SizeOfLayer;
	Neuron *NeuronOfLayer;
public:
	SynapsMatrix Synapses;
	LayerOfNeurons();
	LayerOfNeurons(int size);
	void SetNumberOfLayer(int number);
	void SetSizeOfLayer(int size);
	int GetSizeOfLayer();
	double GetOutputOfNeuron(int index);
	void SetSynapsesForLayer(LayerOfNeurons& PreviousLayer, double StartWeight);
	void LayerOfNeurons::SetSynapsesForLayer(LayerOfNeurons& PreviousLayer);
	SynapsMatrix GetSynapsesForLayer();
	Neuron ReturnNeuron(int i);
	void SetInputOfLayer(LayerOfNeurons& PreviousLayer);
	void SetInputOfLayer(bool isInputNeurons, double *buffSum);
	~LayerOfNeurons();
};

