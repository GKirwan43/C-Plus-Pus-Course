#include <iostream>
using namespace std;

int main()
{
    int numExercises;
    
    double recieved = 0;
    double total = 0;

    cout << "How many exercises to input? \n";
    cin >> numExercises;

    for (int i = 1; i <= numExercises; i++) {
        double tempRecieved;
        double tempTotal;

        cout << "\nScore received for exercise " << i << ":\n";
        cin >> tempRecieved;
        cout << "Total points possible for exercise " << i << ": \n";
        cin >> tempTotal;

        recieved+=tempRecieved;
        total+=tempTotal;

    }

    cout.precision(2);
    cout << "\nYour total is " << fixed << recieved << " out of " << total << ", or " << (recieved/total)*100 << "%.\n";
}

