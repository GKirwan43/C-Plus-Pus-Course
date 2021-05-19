#include <iostream>
using namespace std;

int main() {
    double switchDoor = 0;
    double keepDoor = 0;
    for (int i = 0; i < 10000; i++) {
        double carDoor = rand() % 2 + 1;
        double currentDoor = rand() % 2 + 1;
        double changeDoor = rand() % 2 + 1;
        if (changeDoor==1) {
            if (carDoor==currentDoor) {
                keepDoor++;
            }
        } else {
            if (currentDoor==1) {
                currentDoor = 2;
            } else if (currentDoor==2) {
                currentDoor = 1;
            }
            if (carDoor==currentDoor) {
                switchDoor++;
            }
        }
    }
    cout << "You won " << switchDoor << " times when switching doors.\n";
    cout << "You won " << keepDoor << " times when keeping current door.\n";
    cout << "There is a " << (switchDoor/10000)*100 << "% chance of winning when switching doors.\n";
    cout << "There is a " << (keepDoor/10000)*100 << "% chance of winning when keeping current door.\n";
    return 0;
}