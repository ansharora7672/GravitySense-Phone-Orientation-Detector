#pragma once
//Final OOP Project - Ansh - Adam 
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#define INP_NUM 3
using namespace std;
//Final OOP Project - Ansh - Adam 
class NNclassifier
{
private://attributes of class NNclassifier
	vector<vector<double>> vectors;  //vector from with x y and z coordiantes
	vector<int> labels;  //label integer
public:
	void machinelearning(const string&); //function declarations for reading learning data from the fiel and finding nearest vector to user input
	int findNearestNeighbour(vector<double>&);
};

