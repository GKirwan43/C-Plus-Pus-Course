#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std; 

void new_line(istream& input, string& line) {
    char symbol;
    input.get(symbol);
    line="";
    while (symbol != '\n') {
        line+=symbol;
        input.get(symbol);
        if (symbol=='#') {
            input.ignore();
            input.ignore();
            input.get(symbol);
        }
        if (!input) {
            break;
        }
    }
}

const int NUMBER_OF_CHAPTERS=18;

int main() {
    fstream input("input.dat", ios::in);

    string answer;
    string question;

    int answerCount=0;
    int chapterNumber=18;

    while (true) {
        cout<<"\nQuestion:\n";
        cin>>question;
        new_line(input, answer);
        answerCount++;
        if(answerCount!=1) {
            cout<<answer;
        } else {
            cout<<answer<<chapterNumber<<".";
            chapterNumber--;
            if (chapterNumber==0) {
                chapterNumber=NUMBER_OF_CHAPTERS;
            }
        }
        if (answerCount==8) {
            input.close();
            input.open("input.dat", ios::in);
            answerCount=0;
        }
    }
}