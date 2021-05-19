#include <iostream>
using namespace std;

int main() {
    string response;
    while (true) {
        int temperature;
        int digit1;
        int digit2;
        int digit3;
        int small;
        int large;
        
        while (true) {
            cout << "Enter desired temperature (0-999):\n";
            cin >> temperature;

            if (temperature < 0 || temperature > 999) {
                cout << "Invalid Temperature, must be between 0-999.\n";
            } else {
                break;
            }
        }  

        digit3 = temperature % 10;
        if (temperature/10 >= 1) {
            digit2 = (temperature/10)%10;
        }
        if (temperature/100 >= 1){
            digit1 = (temperature/100)%10;
        }
        
        if (digit1==1 || digit1==4 || digit1==7) {
            small=((digit1-1)*100)+99;
            large=(digit1+1)*100;
            cout << "Closest possible temperatures: " << small << ", " << large << "\n";
        } else if (digit2==1 || digit2==4 || digit2==7) {
            small=(digit1*100)+((digit2-1)*10)+9;
            large=(digit1*100)+((digit2+1)*10);
            cout << "Closest possible temperatures: " << small << ", " << large << "\n";
        } else if (digit3==1 || digit3==4 || digit3==7) {
            small=(digit1*100)+(digit2*10)+(digit3-1);
            large=(digit1*100)+(digit2*10)+(digit3+1);
            cout << "Closest possible temperatures: " << small << ", " << large << "\n";
        } else {
            cout << "You can use that number.\n";
        }

        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
    return 0;
}