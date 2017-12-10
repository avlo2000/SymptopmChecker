#pragma once
#ifndef NEURON_H
#define NEURON_H
#include <math.h>
#include <string>
#include "SynapsMatrix.h"



namespace NeuralNet {
	using namespace std;

	class Neuron
	{
	private:
		double input;
		double output;
		int SizeOfOwnLayer;
	public:	
		Neuron();
		void SetInput(double inp);
		void SetFirstInput(double inp);
		void SetFirstInput(int inp);
		void SetFirstInput(string inp);
		void SetSizeOfOwnLayer(int size);
		int GetSizeOfOwnLayer();
		double GetInput();
		double GetOutput();
		void SetOutput(double outp);
		void SetFirstOutput(double outp);
		double GetDelta(double expcted);
		virtual~Neuron();
	};
#endif // NEURON_H
}