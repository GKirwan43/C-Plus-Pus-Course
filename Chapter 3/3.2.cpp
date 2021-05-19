#include <iostream>
using namespace std;

int main() 
{
    double a;
    double b;
    double c;

    string response;

    while (true) {
        cout << "What's the value of A?\n";
        cin >> a;
        cout << "What's the value of B?\n";
        cin >> b;
        cout << "What's the value of C?\n";
        cin >> c;

        double realSolution1 = (-b+sqrt(pow(b, 2.0)-(4.0*a*c))/(2.0*a));
        double realSolution2 = (-b-sqrt(pow(b, 2.0)-(4.0*a*c))/(2.0*a));
        double discriminant = pow(b, 2.0)-(4*a*c);

        if (discriminant==0) {
            cout << "There is one solution: ";
            if (realSolution1) {
                cout << realSolution1 << ".\n";
            } else if (realSolution2) {
                cout << realSolution2 << ".\n";
            }
        } else if (discriminant>0) {
            cout.precision(2);
            cout << "There are two real solutions: " << realSolution1 << ", " << realSolution2 << ".\n";
        } else if (discriminant<0) {
            if (pow(b,2.0)-((4*a*c)/2.0*a) > 0) {
                cout.precision(2);
                cout << "There are two complex solutions: ";
                cout << fixed << -b << "+sqrt(" << pow(b,2.0)-((4*a*c)/2.0*a) << ")";
                cout << ", " ;
                cout << fixed << -b << "-sqrt(" << pow(b,2.0)-((4*a*c)/2.0*a) << ")";
                cout << ".\n";
            } else {
                cout.precision(2);
                cout << "There are two complex solutions: ";
                cout << fixed << "(" << -b << "+sqrt(" << pow(b,2.0)-(4*a*c)*-1 << ")i)/" << (2.0*a);
                cout << ", " ;
                cout << fixed << "(" << -b << "-sqrt(" << pow(b,2.0)-(4*a*c)*-1 << ")i)/" << (2.0*a);
                cout << ".\n";
            }
        }
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}