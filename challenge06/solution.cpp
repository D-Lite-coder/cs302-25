/* Program Name: prims algorithm
 * Student Name: David Carpenter
 * Net ID: dcarpe23
 * Student ID: 000722316
 * Program Description: breaks a DNA string into substrings and looks for repetitive sequences*/

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main() {

    string dna;

    while (cin >> dna) {


		unordered_map<string, int> subStrings; //all substrings
		set<string> repeats; //repeated substrings
		int length = dna.size();

		//break DNA into substrings and check for reapeats
		for(int index = 0; index <= length - 9; index++)
		{
			string sub = dna.substr(index, 9); //makes substring of length 9

			subStrings[sub]++;
			if(subStrings[sub] == 2) repeats.insert(sub); //if the substring is repeated, add to repeats

		}

		//print results
		for (string sub : repeats) {

			cout << sub << "\n";
		}

		cout << "-1" << endl;

    }


    return 0;
}
