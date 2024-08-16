#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include <ctime>
#include <random>
using std::cin; using std::cout; using std::endl; using std::vector;

class RunAlgorithm
{
private:
	vector<int> *input;
	int number_to_reach;
public:
	RunAlgorithm(int option=0);
	void print();
};

