#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void copyRecordAndAverage(istream& inputFile, ostream& outputFile) {
    outputFile<<left<<setw(15)<<"Last name:"<<setw(15)<<"First name:";

    for (int i=1; i<=10; i++) {
        outputFile<<setw(12)<<right<<setw(7)<<right<<i<<":";
    }

    outputFile<<" Average:"<<"\n";

    string fName, lName;
    int currentScore =0;
    double scoreSum=0;
    int recordedScoreNumber=0;

    while (!inputFile.eof()) {
        inputFile>>lName;
        inputFile>>fName;
        outputFile<<left<<setw(15)<<lName<<left<<setw(15)<<fName;

        inputFile.ignore();
        while (isdigit(inputFile.peek())) {
            recordedScoreNumber++;
            inputFile>>currentScore;
            outputFile<<right<<setw(8)<<currentScore;
            scoreSum+=currentScore;
            inputFile.ignore();
        }

        outputFile<<right<<setw(8*(10-recordedScoreNumber))<<"";
        outputFile<<" "<<right<<setw(7)<<scoreSum/10;

        if (inputFile.peek()!=EOF) {
            outputFile<<"\n";
        }

        recordedScoreNumber=0;
    }
}

void copyInputToOutput(istream& inputFile, ostream& outputFile) {
    string file;
    char next;
    while(inputFile.get(next)) {
        file+=next;
    }
    outputFile<<file;
}

int main() {
    fstream input("input.dat", ios::in);
    fstream output("output.dat", ios::out);

    copyRecordAndAverage(input, output);

    input.close();
    output.close();

    fstream input2("output.dat", ios::in);
    fstream output2("input.dat", ios::out);

    copyInputToOutput(input2, output2);

    input2.close();
    output2.close();
}