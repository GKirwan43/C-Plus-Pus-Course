#include <iostream>
using namespace std;

double mortgage(double initialloan) {
    double credit = .03*initialloan;
    double interest = .06*initialloan;
    return credit+interest;
}

double getTotal(double initialLoan, double taxsave) {
    return mortgage(initialLoan) - taxsave;
}

int main()
{
    while (true) {
        string response;
        double price;
        double downpayment;
        cout << "Price of the house?\n";
        cin >> price;
        cout << "Down payment?\n";
        cin >> downpayment;

        double initialloan = price-downpayment;
        double taxsave = mortgage(initialloan)*.35;

        cout.precision(2);
        cout << fixed << "Annual after-tax cost: $" << getTotal(initialloan, taxsave) << "\n";


        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}