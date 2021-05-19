#include <iostream>
using namespace std;

int main() {
    for (int i=0; i<=9999; i++) {
        int ones = i % 10;
        int tens = (i/10) % 10;
        int hundreds = (i/100) % 10;
        int thousands = (i/1000) % 10;

        if (ones!=tens && ones!=hundreds && ones!=thousands && tens!=hundreds && tens!=thousands && hundreds!=thousands) {
            if (thousands==tens*3) {
                if (i%2!=0) {
                    if (ones+tens+hundreds+thousands==27) {
                        cout << "The address is " << thousands << hundreds << tens << ones << ". \n";
                    }
                }
            }
        }
    }
}