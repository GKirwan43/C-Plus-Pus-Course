#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int PIN_SIZE=5;
int orginalPIN[]={1,2,3,4,5};

int getIndex(int array[], int target, int exclude=-1) {
    for (int i=0;i<10;i++) {
        if (i!=exclude&&target==array[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(100000*time(0));
    
    int displayedNum[10]={-1};
    int enteredNumbers[5];

    for (int i=0;i<10;i++) {
        displayedNum[i]=rand()%10;

        while (getIndex(displayedNum, displayedNum[i], i)>-1) {
            displayedNum[i]=rand()%10;
        }
    }

    cout<<"PIN:";
    
    for(int i =0;i<10;i++) {
        cout<<setw(3)<<i;
    }

    cout<<"\nNUM:";
    
    for(int i;i<10;i++) {
        cout<<setw(3)<<displayedNum[i];
    }

    cout<<"\nEnter correct numbers for your pin:\n";

    for(int i=0;i<PIN_SIZE;i++) {
        cin>>enteredNumbers[i];
    }

    int test=0;

    for (int i=0;i < PIN_SIZE; i++) {
        if (getIndex(displayedNum, enteredNumbers[i])==orginalPIN[i]) {
            test++;
        }
    }

    if (test==PIN_SIZE) {
        cout << "\nCorrect.\n";
    } else {
        cout << "\nIncorrect.\n";
    }
}