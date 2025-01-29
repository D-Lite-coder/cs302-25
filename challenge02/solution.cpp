/* Program name: Closest Numbers
   Student name: David Carpenter
   Net ID: dcarpe23
   Student ID: 000722316
   Program description: will read and sort a given vector of N ints. it will then find the smallest difference between the values. if there are muliple pair with the min difference it will print all of them in accending order */

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Main Execution

int main() {
	
	vector<int> minDiffList;
	string line;

	while (getline(cin, line)) {

		int N = stoi(line); //gets vector size

		//gets number vector
		getline(cin, line);
		stringstream numsLine(line);
		vector<int> nums(N);
		for (int i = 0; i < N; i++)
		{
			numsLine >> nums[i];
		}


	sort(nums.begin(), nums.end());

	int minDiff = INT_MAX;
	int currDiff;
	
	for(int i = 1; i < N; i++) {
			
		currDiff = nums[i] - nums[i-1];

		//compares the difference of the current two numbers in the vector to the current min diff.
		if(currDiff < minDiff) { //clears current vector and adds new min diff.

			minDiff = currDiff;
			minDiffList.clear();
			
			minDiffList.push_back(nums[i-1]);
			minDiffList.push_back(nums[i]);

		}
		else if (currDiff == minDiff) { //adds to min diff vector

			minDiffList.push_back(nums[i-1]);
			minDiffList.push_back(nums[i]);

		}
	
	}

	int vectorSize = minDiffList.size();

	//print min diff vector
	for(int i = 0; i < vectorSize; i++) {

		if(i == vectorSize-1) {

			cout << minDiffList[i] << endl;
		}
		else {

			cout << minDiffList[i] << " ";
		}

	}

	}

    return 0;
}
