#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
using namespace std;

char charsArray[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int intArray[26] = {0};

void update(char c) {
    for (int i=0; i<26; i++) {
        if (charsArray[i]==c) {
            intArray[i]++;
        }
    }
}

void swapi(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void swapc(char *val1, char *val2)
{
    char temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
 
void bubbleSort(char charArr[], int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swapi(&arr[j], &arr[j+1]);
                swapc(&charArr[j], &charArr[j+1]);
            }
        }
    }
}

int main() {
    char next;

    cout<<"Enter text:\n";
    cin.get(next);
    while(next) {
        update(next);
        cin.get(next);
        if (next=='.') {
            break;
        }
    }

    bubbleSort(charsArray, intArray, 26);

    cout<<"-------------------------------------\n";
    cout<<"| Letter | Number of Occurences     |\n";
    cout<<"-------------------------------------\n";

    for (int i=0; i<26; i++) {
        if (intArray[i]!=0) {
            cout<<"|"<<setw(3)<<charsArray[i]<<"     |    "<<setw(10)<<intArray[i]<<setw(14)<<" |\n";
        }
    }

    cout<<"-------------------------------------\n";
}

