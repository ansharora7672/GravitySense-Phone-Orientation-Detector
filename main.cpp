#include "AnotherClassifier.h"
#include "NNclassifier.h"
using namespace std;

//Final OOP Project - Ansh - Adam 

int main()
{
    NNclassifier nn;
    //trainingData text file is provided to perform machine learning algorithm
    nn.machinelearning("trainingData.txt");

    //vector to store user input..double values...
    vector<double> userInputVector;
    cout << "Enter 3 input data values : "<<endl;

    string input;
    getline(cin, input);  // Reading the line..
    istringstream iss(input);
    string token;

    for (int i = 0; i < INP_NUM; ++i)
    {
        //reading the user input line seperated by  comma ','.....
        getline(iss, token, ',');

        //input validation to ensure user input vector.....
        if (token.find_first_not_of("0123456789.-") != string::npos) 
        {
            cout << "Invalid Input ---- ONLY DOUBLE VALUES SEPERATED BY ',' between 1 and -1.......\n";
            userInputVector.clear();  // clear vector when invalid input......
            break;
        }

        try 
        {
            double temp = stod(token); //passes a value of a string converted to double to a double variable so taht it can be pushed into vector
            userInputVector.push_back(temp); //

        }
        catch (const invalid_argument&) 
        {
            cout << "Invalid input. Please enter valid double values separated by commas.\n";
            userInputVector.clear();  // clear vector when invalid input......
            break;
        }
    }

    if (userInputVector.size() != INP_NUM) 
    {
        cout << "Please provide three valid double values.\n";
        return 1;  // returns 1...
    }

    int nearestLabel = nn.findNearestNeighbour(userInputVector); //calls for function to find the nearest vector from learning file to the user input vector

    cout << "Nearest label -> " << nearestLabel; 

    //if condititon to check orientation according to label...
    if (nearestLabel == 1) 
    {
        cout << ": Face Up" << endl;
    }
    else if (nearestLabel == 2)
    {
        cout << ": Face Down" << endl;
    }
    else if (nearestLabel == 3)
    {
        cout << ": Portrait" << endl;
    }
    else if (nearestLabel == 4)
    {
        cout << ": Portrait Upside Down" << endl;
    }
    else if (nearestLabel == 5)
    {
        cout << ": Landscape Left" << endl;
    }
    else if (nearestLabel == 6)
    {
        cout << ": Landscape Right" << endl;
    }
    return 0;
}
