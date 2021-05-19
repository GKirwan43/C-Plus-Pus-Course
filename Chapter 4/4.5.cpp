#include <iostream>
using namespace std;

double calForBMR(double weight) {
    return pow(70*(weight/2.2), .0756);
}

double calForPA(double intensity, double weight, double minutes) {
    return .0385 * intensity * weight * minutes;
}

int main()
{
    while (true) {
        string response;
        double weight;
        double intensity;
        double minutes;
        double calories;

        cout << "Weight?\n";
        cin >> weight;
        cout << "Intensity?\n";
        cin >> intensity;
        cout << "Minutes?\n";
        cin >> minutes;
        cout << "Calories?\n";
        cin >> calories;

        double totalCalNeeded = calForBMR(weight) + calForPA(intensity, weight, minutes) + (calories*.1);

        cout << "You will need to eat " << totalCalNeeded/calories << " servings of that food to maintain your current body weight.\n";

        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}