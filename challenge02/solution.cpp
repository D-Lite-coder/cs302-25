// Challenge 02: Closest Numbers
// Name:  xxxxx

// Brief description:

// This code solves yyyy based on the following idea/implementation...

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

	int index = 1;
	while (index < argc) {

		int N = stoi(argv[index]);
		index++;
	
	vector<int> nums(N);

	for(int i = 0; i < N; i++, index++) {
	
		nums[i] = stoi(argv[index]);
	}

	sort(nums.begin(), nums.end());

	int minDiff = INT_MAX;
	int currDiff, numOne, numTwo;
	
	for(int i = 1; i < N; i++) {
			
		currDiff = nums[i] - nums[i-1];

		if(currDiff < minDiff) {

			numOne = nums[i-1];
			numTwo = nums[i];

			minDiff = currDiff;

		}
	
	}

	cout << numOne << " " << numTwo << endl;

	}

    return 1;
}
