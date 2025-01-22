/* Program Name: Array Shifter
 * Student Name: David Carpenter
 * Net ID: dcarpe23
 * Student ID: 000722316
 * Program Description: Shifts an array of n values r times to the left or right*/

#include <vector>
#include <iostream>
#include <sstream>


using namespace std;

vector<int> rotateArray(int n, int r, char d, const vector<int>& array)
{
	vector<int> rotatedArray(n);

	//left shift: rotates left by r positions
	if(d == 'L')
	{
		for(int i = 0; i < n; i++)
		{
			rotatedArray[i] = array[(i + r) % n];
		}
	}
	//right shift: rotates right by r positions
	else if(d == 'R')
	{
		for(int i = 0; i < n; i++)
		{
			rotatedArray[i] = array[(i - r + n) % n];
		}
	}
	else
	{
		cerr << "INVALID DIRECTION\n";
	}

	return rotatedArray;
}



int main() {

string line;

vector<string> rotatedResults;

int n, r;
char d;

while (getline(cin, line))
{
	//read the defining line
	stringstream defineLine(line);
	defineLine >> n >> r >> d;

	//read the array
	getline(cin, line);
	stringstream arrayLine(line);
	vector<int> array(n);
	for (int i = 0; i < n; i++)
	{
		arrayLine >> array[i];
	}

	//preform the rotation
	vector<int> rotatedArray = rotateArray(n, r, d, array);

	//store the results as a string in results vector
	stringstream result;
	for(int i = 0; i < n; i++)
	{
		result << rotatedArray[i] << (i < n - 1 ? " " : "\n"); //https://cplusplus.com/doc/tutorial/operators/ ternary operator used to remove space from end of array
	}

	rotatedResults.push_back(result.str());

}

//outputs all results
for (string& result : rotatedResults)
{
	cout << result;
}


return 0;
}
