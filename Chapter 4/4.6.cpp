#include <iostream>
using namespace std;

double getMoneyFromString(string moneyResponse) {
    if (moneyResponse=="Dollar"||moneyResponse=="dollar") {
        return 1;
    } else if (moneyResponse=="Quarter"||moneyResponse=="quarter") {
        return .25;
    } else if (moneyResponse=="Dime"||moneyResponse=="dime") {
        return .10;
    } else if (moneyResponse=="Nickel"||moneyResponse=="nickel") {
        return .05;
    }
    return 0;
}

double getChange(double money) {
    return money-3.5;
}

int main()
{
    while (true) {
        string response;
        double money=0;

        while (money<3.5) {
            string moneyResponse;
            
            cout.precision(2);
            cout << fixed << "Amount Inserted: $" << money << ".\n";
            cout << "Insert money (Dollar, Quarter, Dime, Nickel).\n";
            cin >> moneyResponse;
            cout << "\n";

            money+=getMoneyFromString(moneyResponse);
        }

        cout << "Enjoy your deep-fried twinkie.\n";
        
        if (money>3.5) {
            cout.precision(2);
            cout << fixed << "Your change is $" << getChange(money) << ".\n";
        } else {
            cout << "You have no change.\n";
        }

        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}