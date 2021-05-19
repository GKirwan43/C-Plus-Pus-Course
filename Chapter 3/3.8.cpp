#include <iostream>
using namespace std;

int main() {
    string response;
    while (true) {
        double n;
        double pi = 0;
        cout << "Enter n: \n";
        cin >> n;
        for (int i = 0; i < n; i++) {
            pi+=pow(-1,i)/((2*i)+1);
        }
        pi=pi*4;
        cout << "Approximation of Pi: " << pi << "\n";
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
    return 0;
}