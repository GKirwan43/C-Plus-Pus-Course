#include <iostream>
using namespace std;
  
int main()
{
    string response;
    int startHour, startMinutes;
    int waitHour, waitMinutes;
    int totalHour, totalMinutes;

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

        if (totalMinutes!=0) {
            cout << "Time after wait is " << totalHour << ":" << totalMinutes << ".\n";
        } else {
            cout << "Time after wait is " << totalHour << ":" << totalMinutes << "0.\n";
        }
        
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}