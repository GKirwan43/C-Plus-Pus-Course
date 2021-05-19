#include <iostream>
using namespace std;

int main()
{
    int start;
    int end;

    cout << "Enter starting tempertature: \n";
    cin >> start;
    cout << "Enter ending temperature: \n";
    cin >> end;

    for (int i = start; i <= end; i++) {
        cout << "At " << i << " degrees Celsius the velocity of sound is ";
        cout.precision(4);
        cout << 331.3+(0.61*i) << " m/s\n";
    }

    return 0;
}