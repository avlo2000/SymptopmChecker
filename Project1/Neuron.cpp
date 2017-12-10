#include "Neuron.h"
#include "SynapsMatrix.h"
#include <string.h>
#include <iostream>

double sigmoid(double x)
{
	double exp_value;
	double return_value;
	exp_value = exp((double)-x);
	return_value = 1 / (1 + exp_value);

	return return_value;
}

double sigmoid_derivative(double x)
{
	double return_value;
	return_value = sigmoid(x)*(1 - sigmoid(x));
	return return_value;
}

namespace NeuralNet {
	
	
	Neuron::Neuron()
	{
		input = 0;
	}

	void Neuron::SetInput(double inp)
	{
		input = inp;
	};
	void Neuron::SetFirstInput(double inp)
	{
		input = inp;
	};
	void Neuron::SetFirstInput(int inp)
	{
		input = inp;
	};
	void Neuron::SetFirstInput(string inp)
	{
		int sum = 0;
		for (int i = 0; i < inp.length(); ++i)
		{
			sum += inp[i];
		}
		input = sum;
	};
	void Neuron::SetSizeOfOwnLayer(int size)
	{
		SizeOfOwnLayer = size;
	};
	int Neuron::GetSizeOfOwnLayer()
	{
		return SizeOfOwnLayer;
	};
	double Neuron::GetInput()
	{
		return  input;
	};
	double Neuron::GetOutput()
	{
		return output;
	};
	void Neuron::SetOutput(double outp)
	{
		output = sigmoid(outp);
	};
	void Neuron::SetFirstOutput(double outp)
	{
		output = outp;
	};
	double Neuron::GetDelta(double error)
	{
		double delta = error * sigmoid_derivative(output);
		return delta;
	}
	Neuron::~Neuron()
	{

	}

}