#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;

    cout<<"Enter name:\n";
    getline(cin, fullName);

    string firstName=fullName.substr(0, fullName.find(" "));

    firstName+=" ";
    fullName.erase(0, fullName.find(" ")+1);

    string middleInitial;
    int spaceIndex=fullName.find(" ");

    if (spaceIndex<fullName.size()) {
        middleInitial=fullName[0];
        middleInitial+=".";
        fullName.erase(0, spaceIndex+1);
    }

    string lastName=fullName;

    lastName+=", ";

    cout<<lastName<<firstName<<middleInitial<<"\n";
}