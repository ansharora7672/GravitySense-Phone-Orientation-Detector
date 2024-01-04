#include "NNclassifier.h"

//Final OOP Project - Ansh - Adam 

void NNclassifier::machinelearning(const string& filename) //takes name of the file (trainidnData) as a parameter
{
	ifstream inputFile(filename); //open file for output
	if (!inputFile.is_open()) //if file is not opening/empty then print error message
	{
		cout<< "Error !!! CANNOT OPEN FILE  --  " << filename << endl; 
		return;
	}

	string line;
	while (getline(inputFile, line)) //while there are still lines in the file to go through keep going
	{
		istringstream iss(line);
		vector<double> v;
		char comma;
		for (int i = 0; i < INP_NUM; i++) //for each coordinate of the vector
		{
			double temp;
			iss >> temp >> comma;
			v.push_back(temp);
		}
		int label;  // current lable from the file .....it's just initiation....
		iss >> label;  //sends label element from file into the label..
		vectors.push_back(v); //add element to coordinate vector
		labels.push_back(label); //edd element to label vector
	}
	inputFile.close();//close the file
}

int NNclassifier::findNearestNeighbour(vector<double>& userInputVector)
{
	int NNlabel = -1; //initialize label as -1 label to 
	double NNdistance = 9999999999999999999; //initiate closest distance to a high value to ensure that next vector will be closer 

	//for loop to go over every vector in the file...
	for (size_t i = 0; i < vectors.size(); i++)
	{
		double distance = 0; // distanceof the current vector..


		for (int j = 0; j <INP_NUM; j++) // for each coordinate of the vector(x y and z)
		{
			//distance calculating betyween user vecotr and current vector...

			double difference = userInputVector[j] - vectors[i][j]; 
			distance = distance + difference * difference;
		}

		//calculating the square root for real distance...
		distance = sqrt(distance);

		//if condition to check is the current distance is smaller than current nearest neighbour distance....
		//then set nearest neighbour label to current label...
		if (distance < NNdistance)
		{
			NNdistance = distance;
			NNlabel = labels[i];
		}
	}
	return NNlabel;//return label after finding the nearest neighbour
}