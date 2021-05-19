#include <iostream>
using namespace std;

int main()
{
    double li;
    double a;
    double td;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter L Initial: ";
    cin >> li;
    cout << "Enter T Delta: ";
    cin >> td;

    double ld = li*a*td;

    if (ld >= 0) {
        cout << "The material will expand by " << ld << "\n";
    } else {
        cout << "The material will contract by " << ld*-1 << "\n";
    }
}