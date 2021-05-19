#include <iostream>
using namespace std;

int main()
{
    int quarters, dimes, nickels;
    
    cout << "Enter a number of quarters:\n";

    cin >> quarters;

    cout << "Enter a number of dimes:\n";

    cin >> dimes;

    cout << "Enter a number of nickels:\n";

    cin >> nickels;

    int total = (quarters*25)+(dimes*10)+(nickels*5);

    cout << "The total worth of the coins is ";
    cout << total;
    cout << " cents.\n";
    
    return 0;
}