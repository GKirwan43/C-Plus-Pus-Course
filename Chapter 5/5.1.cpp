#include <iostream>
using namespace std;

void input(int& hour, int& minutes) {
    cout << "Enter hour (24 hour notation):\n";
    cin >> hour;
    cout << "Enter minutes:\n";
    cin >> minutes;
}

void conversion(int& hour, char& amPm) {
    if (hour==12) {
        amPm='P';
    } else if (hour==24) {
        hour = hour - 12;
        amPm='A';
    } else if (hour > 12) {
        hour = hour - 12;
        amPm='P';
    } else {
        amPm='A';
    }
}

void output(int hour, int minutes, char amPm) {
    string amPmStr;
    
    if (amPm=='A') {
        amPmStr="AM";
    } else if (amPm=='P') {
        amPmStr="PM";
    }
    
    if (minutes!=0) {
        cout << "The coversion to 12 hour format is " << hour << ":" << minutes << " " << amPmStr << "\n";
    } else {
        cout << "The coversion to 12 hour format is " << hour << ":" << minutes << "0 " << amPmStr << "\n";
    }
}
  
int main()
{
    string response;
    int hour, minutes;
    char amPm;

    while (true) {
        input(hour, minutes);
        conversion(hour, amPm);
        output(hour, minutes, amPm);

        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}