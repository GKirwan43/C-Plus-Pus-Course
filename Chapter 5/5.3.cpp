#include <iostream>
using namespace std;
  
int main()
{
    string response;
    int startHour, startMinutes;
    int waitHour, waitMinutes;
    int totalHour, totalMinutes;
    string amPm;

    while (true) {
        cout << "Current Hour (24 Hour Notation):\n";
        cin >> startHour;
        cout << "Current Minutes:\n";
        cin >> startMinutes;
        cout << "Wait Hour (24 Hour Notation):\n";
        cin >> waitHour;
        cout << "Wait Minutes:\n";
        cin >> waitMinutes;

        totalHour=startHour+waitHour;
        totalMinutes=startMinutes+waitMinutes;
        totalHour+=floor(totalMinutes/60);
        totalMinutes=totalMinutes%60;
        totalHour=totalHour%24;

        cout << totalHour << "\n";

        if (totalHour==0) {
            totalHour=12;
            amPm="AM";
        } else if (totalHour<12) {
            amPm="AM";
        } else if (totalHour!=12) {
            totalHour-=12;
            amPm="PM";
        } else {
            amPm="PM";
        }

        if (totalMinutes!=0) {
            cout << "Time after wait is " << totalHour << ":" << totalMinutes << " " << amPm << ".\n";
        } else {
            cout << "Time after wait is " << totalHour << ":" << totalMinutes << "0 " << amPm << ".\n";
        }
        
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}