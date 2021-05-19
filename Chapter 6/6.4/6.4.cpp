#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std; 

string exitChar = ".?!,;";

void calculate(ifstream& input)
{
    int numWords = 0;
    int numChars = 0;
    string word;

    cout << fixed << setprecision(0); 

    while(input >> word)
    {
        numWords++;
        int len = word.length();
        if(exitChar.find(word[len-1]) != string::npos) {
            word.erase(len-1);
        }
        numChars += word.length();
    }

    cout << "Average letters per word was " << double(numChars) / numWords << "\n";
}


int main() 
{ 
    ifstream input("input.dat");

    calculate(input);
    input.close();

    cout << "Press Enter to exit";
    cin.get();
}