#include <iostream>
using namespace std;

void compute_coins(int coin_value, int& num, int& amount_left) {
    num=amount_left/coin_value;
    amount_left=amount_left%coin_value;
}
  
int main()
{
    string response;
    int originalChange;
    int change;
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    while (true) {
        cout << "Enter change 1-99:\n";
        cin >> originalChange;

        quarters=0;
        dimes=0;
        nickels=0;
        pennies=0;

        change = originalChange;

        while (change>0) {
            compute_coins(25, quarters, change);
            compute_coins(10, dimes, change);
            compute_coins(5, nickels, change);
            compute_coins(1, pennies, change);
        }

        cout << originalChange << " can be given as\n";

        if (quarters>0) {
            cout << quarters << " quarter(s) ";
        }
        if (dimes>0) {
            cout << dimes << " dime(s) ";
        }
        if (nickels>0) {
            cout << nickels << " nickel(s) ";
        }
        if (pennies>0) {
            cout << pennies << " penny(pennies) ";
        }

        cout << "\n";
        
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}