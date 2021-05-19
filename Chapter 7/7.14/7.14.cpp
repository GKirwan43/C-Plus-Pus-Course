#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std; 

void lookupName(string targetName, string boys[], string girls[], int size, int& boyRank, int& girlRank) {
    boyRank=0;
    girlRank=0;
    for (int i=0; i<size; i++) {
        if (boys[i]==targetName) {
            boyRank=i+1;
        }
        if (girls[i]==targetName) {
            girlRank=i+1;
        }
    }
}

int main() {
    fstream input("babynames2012.txt", ios::in);

    string boys[1000];
    string girls[1000];
    string inputName;
    int boyRank=0;
    int girlRank=0;
    int ignore=0;

    cout<<"Enter name:\n";
    cin>>inputName;

    for(int i=0;i<1000;i++) {
        input>>ignore>>boys[i]>>girls[i];
    }

    lookupName(inputName, boys, girls, 1000, boyRank, girlRank);

    if (boyRank&&girlRank) {
        cout<<inputName<<" is ranked "<<boyRank<<" in popularity among boys.\n";
        cout<<inputName<<" is ranked "<<girlRank<<" in popularity among girls.\n";
    } else if (boyRank) {
        cout<<inputName<<" is ranked "<<boyRank<<" in popularity among boys.\n";
        cout<<inputName<<" is not ranked among the top 1000 girl names.\n";
    } else if (girlRank) {
        cout<<inputName<<" is ranked "<<girlRank<<" in popularity among boys.\n";
        cout<<inputName<<" is not ranked among the top 1000 boy names.\n";
    } else {
        cout<<inputName<<" is not ranked among the top 1000 boy names.\n";
        cout<<inputName<<" is not ranked among the top 1000 girl names.\n";
    }
}