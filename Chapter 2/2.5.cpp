#include <iostream>
using namespace std;

int main()
{
    int roomCapacity, people;

    cout << "Enter the maximum room capacity: \n";
    cin >> roomCapacity;

    cout << "Enter the number of people: \n";
    cin >> people;

    if (roomCapacity>=people)
    {
        cout << "It is legal to hold the meeting and a max of ";
        cout << roomCapacity-people;
        cout << " people can be added to the meeting.\n";
    } else {
        cout << "The meeting cannot be held because of fire regulations, ";
        cout << people-roomCapacity;
        if (people-roomCapacity>1)
        {
            cout << " people need to be excluded to meet fire regulations.\n";
        } else {
            cout << " person needs to be excluded to meet fire regulations.\n";
        }
    }

    return 0;
}