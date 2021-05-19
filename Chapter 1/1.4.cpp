#include <iostream>
using namespace std;

int main()
{
    int seconds;

    cout << "Enter seconds: \n";

    cin >> seconds;

    int distance = (32*pow(seconds,2))/2;

    cout << "The distance is ";
    cout << distance;
    cout << ".\n";

    return 0;
}