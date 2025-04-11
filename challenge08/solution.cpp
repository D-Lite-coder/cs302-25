/* Program Name: Global Sequence Aligner
 * Student Name: David Carpenter
 * Net ID: dcarpe23
 * Student ID: 000722316
 * Program Description: takes in genetic sequences and alligns them. outputs the global alignment */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	//define the values for global allignment
	int match = 1;
    int mismatch = -1;
    int gap = -1;
	string seq1, seq2;

	//takes in values
	while(cin >> seq1) {

		if (cin >> seq2) {
	
			int m = seq1.size();
			int n = seq2.size();

			//initialize graph
			vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

			// Initialize base cases
			for (int i = 0; i <= m; ++i) {
				dp[i][0] = i * gap;
			}
    
			for (int j = 0; j <= n; ++j) {
				dp[0][j] = j * gap;
			}

			// Fill in graph
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= n; ++j) {
					int score = (seq1[i - 1] == seq2[j - 1]) ? match : mismatch;
					dp[i][j] = max({

						dp[i - 1][j - 1] + score, // match/mismatch
						dp[i - 1][j] + gap,       // gap in seq2
						dp[i][j - 1] + gap        // gap in seq1

					});
				}
   
			}

			cout << dp[m][n] << endl;
			
		}
	}
    return 0;
}


