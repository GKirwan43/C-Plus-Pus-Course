#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

double menProbabilities[120]={0};
double womenProbabilities[120]={0};

void calculate(double to[], double from[], int size) {
    for (int i=0;i<size;i++) {
        to[i]=from[i];
    }
}

void getProbabilities(istream& stream, double probabilities1[], double probabilities2[]) {
    double ignore=0;
    for (int i=0;i<120;i++) {
        stream>>ignore>>probabilities1[i]>>probabilities2[i];
    }
}

int main() {
    srand(100000*time(0));

    double malesDeathProbability[120]={0};
    double femalesDeathProbability[120]={0};
    double deathProbability[120]={0};

    fstream input("LifeDeathProbability.txt", ios::in);

    getProbabilities(input, malesDeathProbability, femalesDeathProbability);
    input.close();

    double randomNumber=rand()/10000000;

    char gender;
    int age=0;

    cout<<"Gender (m or f):\n";
    cin>>gender;
    cout<<"Age:\n";
    cin>>age;

    if(gender=='m') {
        calculate(deathProbability, malesDeathProbability, 120);
    } else {
        calculate(deathProbability, femalesDeathProbability, 120);
    }

    while (age<120&&randomNumber>deathProbability[age]) {
        randomNumber=rand()/10000000;
        age++;
    }

    cout<<"\nThat person will live to the age of "<<age<<".\n";
}