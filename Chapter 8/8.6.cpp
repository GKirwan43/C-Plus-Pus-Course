#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{	
	string response;
	while (true) {
		string str;
		string newStr;

		cout << "Enter text: \n";

		getline(cin, str);

		istringstream ss(str);
	
		string word;
		while (ss >> word) 
		{
			bool containsText=false;
			for (int i=0;i<word.length();i++) {
				if (isalpha(word[i])) {
					containsText=true;
				}
			}
			if (containsText) {
				newStr+=word;
			} else {
				for (int i=0;i<word.length();i++) {
					newStr+="x";
				}
			}
			newStr+=" ";
		}

		cout << newStr << "\n";

		cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
		cin.ignore();
	}
}