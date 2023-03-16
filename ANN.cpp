#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Sigmoid activation function
double sigmoid(double x) {
  return 1 / (1 + exp(-x));
}

// Derivative of sigmoid function
double sigmoidDerivative(double x) {
  return x * (1 - x);
}

// A single neuron
struct Neuron {
  vector<double> weights;
  double bias;

  // Constructor
  Neuron(int numWeights) {
    // Initialize weights randomly between -1 and 1
    for (int i = 0; i < numWeights; i++) {
      weights.push_back((double)rand() / RAND_MAX * 2 - 1);
    }
    // Initialize bias randomly between -1 and 1
    bias = (double)rand() / RAND_MAX * 2 - 1;
  }

  // Feedforward function
  double feedforward(vector<double> inputs) {
    double sum = bias;
    for (int i = 0; i < weights.size(); i++) {
      sum += weights[i] * inputs[i];
    }
    return sigmoid(sum);
  }
};

// A layer of neurons
struct NeuronLayer {
  vector<Neuron> neurons;

  // Constructor
  NeuronLayer(int numNeurons, int numInputsPerNeuron) {
    for (int i = 0; i < numNeurons; i++) {
      neurons.push_back(Neuron(numInputsPerNeuron));
    }
  }

  // Feedforward function
  vector<double> feedforward(vector<double> inputs) {
    vector<double> outputs;
    for (int i = 0; i < neurons.size(); i++) {
      outputs.push_back(neurons[i].feedforward(inputs));
    }
    return outputs;
  }
};

// An artificial neural network
struct ANN {
  vector<NeuronLayer> layers;

  // Constructor
  ANN(vector<int> topology) {
    for (int i = 1; i < topology.size(); i++) {
      layers.push_back(NeuronLayer(topology[i], topology[i - 1]));
    }
  }

  // Feedforward function
  vector<double> feedforward(vector<double> inputs) {
    vector<double> outputs = inputs;
    for (int i = 0; i < layers.size(); i++) {
      outputs = layers[i].feedforward(outputs);
    }
    return outputs;
  }
};

int main() {
  // Create a new ANN with 2 input neurons, 3 hidden neurons, and 2 output neurons
  ANN ann({2, 3, 2});

  // Feedforward a test input
//   vector<double> outputs = ann.feedforward({1, 2});

float input_1;
cout << "Input-1: ";
cin >> input_1;
float input_2;
cout << "Input-2: ";
cin >> input_2;
  vector<double> outputs = ann.feedforward({input_1, input_2});
  cout << "Inputs: " << input_1 << " " << input_2 << endl;


cout << "Outputs: ";
  // Print the output
  cout << outputs[0] << " " << outputs[1] << endl;

  return 0;
}
