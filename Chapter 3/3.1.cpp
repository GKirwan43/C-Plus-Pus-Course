#include <iostream>
using namespace std;

int main()
{
    string response;
    int startHour;
    int length;
    double cost;

    while (true) {
        string tempDayOfWeek;
        char letter1;
        char letter2;
        cout << "What is the day of the week?\n";
        cin >> tempDayOfWeek;
        letter1 = toupper(tempDayOfWeek.at(0));
        letter2 = tolower(tempDayOfWeek.at(1));

        cout << "What's the start time? (24 Hour Notation)\n";
        cin >> startHour;
        cin.ignore(':', '\n');

        cout << "How long were you on the call? (Minutes)\n";
        cin >> length;
        if (letter1=='M' || letter1=='T' || letter1=='W' || letter1=='F') {
            if (startHour >= 8 && startHour < 18) {
                cost = .4*length;
            } else {
                cost = .25*length;
            }
        } else {
            cost = .15*length;
        }
        cout.precision(2);
        cout << fixed << "Your bill will cost $" << cost << ".\n";

        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}