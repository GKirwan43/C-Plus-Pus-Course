#include <iostream>
using namespace std;

int main()
{
    string tens[8] = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string teens[9] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string ones[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string fixedOnes[11] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    for (int i = 7; i>=0; i--) {
        for (int j = 9; j >= 0; j--) {
            if (j==0) {
                cout << tens[i] << " bottles of beer on the wall.\n";
                cout << "\n";
                cout << tens[i] << " bottles of beer on the wall,\n";
                cout << tens[i] << " bottles of beer,\n";
                cout << "Take one down, pass it around,\n";
            } else {
                if (i!=7||j!=9) {
                    cout << tens[i] << "-" << ones[j] << " bottles of beer on the wall.\n";
                    cout << "\n";
                }
                cout << tens[i] << "-" << ones[j] << " bottles of beer on the wall,\n";
                cout << tens[i] << "-" << ones[j] << " bottles of beer,\n";
                cout << "Take one down, pass it around,\n";
            }
        }
    }
    for (int i = 8; i>=0; i--) {
        cout << teens[i] << " bottles of beer on the wall.\n";
        cout << "\n";
        cout << teens[i] << " bottles of beer on the wall,\n";
        cout << teens[i] << " bottles of beer,\n";
        cout << "Take one down, pass it around,\n";
    }
    for (int i = 10; i>=0; i--) {
        cout << fixedOnes[i] << " bottles of beer on the wall.\n";
        cout << "\n";
        if (i==1) {
            cout << fixedOnes[i] << " bottle of beer on the wall,\n";
            cout << fixedOnes[i] << " bottle of beer,\n";
            cout << "Take one down, pass it around,\n";
        } else if (i!=0) {
            cout << fixedOnes[i] << " bottles of beer on the wall,\n";
            cout << fixedOnes[i] << " bottles of beer,\n";
            cout << "Take one down, pass it around,\n";
        }
    }
    return 0;
}