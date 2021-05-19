#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year%400==0) {
        return true;
    } else {
        return false;
    }
}

int getCenturyValue(int year) {
    int century = (year/100)%100;
    int remainder = century%4;
    int subtract = 3-remainder;
    return subtract*2;
}

int getYearValue(int year) {
    int yearInCentury = year%100;
    int divide = yearInCentury/4;
    return yearInCentury+divide;
}

int getMonthValue(int month, int year) {
    if (isLeapYear(year)) {
        if (month==1) {
            return 6;
        } else if (month==2) {
            return 2;
        }
    } else {
        if (month==1) {
            return 0;
        } else if (month==2) {
            return 3;
        }
    }
    if (month==3) {
        return 3;
    } else if (month==4) {
        return 6;
    } else if (month==5) {
        return 1;
    } else if (month==6) {
        return 4;
    } else if (month==7) {
        return 6;
    } else if (month==8) {
        return 2;
    } else if (month==9) {
        return 5;
    } else if (month==10) {
        return 0;
    } else if (month==11) {
        return 3;
    } else if (month==12) {
        return 5;
    }
    return 0;
}

int main()
{
    string response;

    while (true) {
        int month;
        int day;
        int year;

        cout << "Enter Month (Number):\n";
        cin >> month;
        cout << "Day:\n";
        cin >> day;
        cout << "Year:\n";
        cin >> year;

        int currentDay=(day+getMonthValue(month, year)+getYearValue(year)+getCenturyValue(year))%7;

        if (currentDay==0) {
            cout << "The day is Sunday.\n";
        } else if (currentDay==1) {
            cout << "The day is Monday.\n";
        } else if (currentDay==2) {
            cout << "The day is Tuesday.\n";
        } else if (currentDay==3) {
            cout << "The day is Wednesday.\n";
        } else if (currentDay==4) {
            cout << "The day is Thursday.\n";
        } else if (currentDay==5) {
            cout << "The day is Friday.\n";
        } else if (currentDay==6) {
            cout << "The day is Saturday.\n";
        }
        
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}