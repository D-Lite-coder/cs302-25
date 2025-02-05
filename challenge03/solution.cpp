/* Program Name: palindrome tester
 * Student Name: David Carpenter
 * Net ID: dcarpe23
 * Student ID: 000722316
 * Program Description: tests a string to see if it is a palindrome permutation*/
#include <iostream>
#include <cctype>
#include <unordered_set>

using namespace std;

//format a string to remove spaces and only be lower case letters.
string formatString(string s) {

  string result = "";

  for (size_t i = 0; i < s.length(); i++) {

    if (isalpha(s[i])) {

        result += tolower(s[i]);
    }

  }

  return result;
}

//tests a string by counting the number of specific chars in a string. a permutation can at most have one odd char count
bool is_Palindrome(const string& s) {

	unordered_set<char> myPal;
  
	for (size_t i = 0; i < s.length(); i++) {
	
		if(myPal.count(s[i])) { //if the char is in the set, remove it (even)
			myPal.erase(s[i]);
		}
		else {
			myPal.insert(s[i]);
		}

	}

	return myPal.size() <= 1;
}

int main() {

  string line;
  bool truePal;

  //test every line
  while(getline(cin, line))
  {
	string formatLine = formatString(line);

	truePal = is_Palindrome(formatLine); //test if the formated line is a palindrome

	//output
	if(truePal) {

		cout << "\"" << line << "\"" << " is a palindrome permutation" << endl;
	}
	else {

		cout << "\"" << line << "\"" << " is not a palindrome permutation" << endl;
	}
	
  }

  return (0);
}
