
#include <iostream>
#include<cstdlib>
#include<string>
#include <string>
using namespace std;

void getHex(istream& stream, char charArray[]) {
    string temp;
    stream>>temp;
    for (int i = 0; i<10; i++) {
        charArray[i]=temp[i];
    }
}

void convertCharToInt(char charArr[], int intArr[]) {
    for (int i = 0; i<10; i++) {
        if (charArr[i]=='0') intArr[i]=0;
        else if (charArr[i]=='1') intArr[i]=1;
        else if (charArr[i]=='2') intArr[i]=2;
        else if (charArr[i]=='3') intArr[i]=3;
        else if (charArr[i]=='4') intArr[i]=4;
        else if (charArr[i]=='5') intArr[i]=5;
        else if (charArr[i]=='6') intArr[i]=6;
        else if (charArr[i]=='7') intArr[i]=7;
        else if (charArr[i]=='8') intArr[i]=8;
        else if (charArr[i]=='9') intArr[i]=9;
        else if (charArr[i]=='a') intArr[i]=10;
        else if (charArr[i]=='b') intArr[i]=11;
        else if (charArr[i]=='c') intArr[i]=12;
        else if (charArr[i]=='d') intArr[i]=13;
        else if (charArr[i]=='e') intArr[i]=14;
        else if (charArr[i]=='f') intArr[i]=15;
    }
}

void covertIntToChars(char charArr[], int intArr[]) {
    for (int i = 0; i<10; i++) {
        if (intArr[i]==0) charArr[i]=0;
        else if (intArr[i]==1) charArr[i]='1';
        else if (intArr[i]==2) charArr[i]='2';
        else if (intArr[i]==3) charArr[i]='3';
        else if (intArr[i]==4) charArr[i]='4';
        else if (intArr[i]==5) charArr[i]='5';
        else if (intArr[i]==6) charArr[i]='6';
        else if (intArr[i]==7) charArr[i]='7';
        else if (intArr[i]==8) charArr[i]='8';
        else if (intArr[i]==9) charArr[i]='9';
        else if (intArr[i]==10) charArr[i]='a';
        else if (intArr[i]==11) charArr[i]='b';
        else if (intArr[i]==12) charArr[i]='c';
        else if (intArr[i]==13) charArr[i]='d';
        else if (intArr[i]==14) charArr[i]='e';
        else if (intArr[i]==15) charArr[i]='f';
    }
}

bool convert(int intArr1[], int intArr2[], int sum[]) {
    int extra=0;

    for (int i=9;i>=0;i--) {
        sum[i]=intArr1[i]+intArr2[i]+extra;
        extra=sum[i]/16;
        sum[i]=sum[i]%16;
    }

    if (extra==0) {
        return true;
    }

    return false;
}

int main() {
    string response;

    while (true) {
        char char1[10]={'0'};
        char char2[10]={'0'};
        int int1[10]={0};
        int int2[10]={0};
        int intResult[10]={0};
        char charResult[10]={'0'};
        cout<<"Enter first ten digit hexadecimal:\n";
        getHex(cin, char1);

        cout<<"Enter second ten digit hexadecimal:\n";
        getHex(cin, char2);

        convertCharToInt(char1, int1);
        convertCharToInt(char2, int2);

        if (convert(int1, int2, intResult)) {
            covertIntToChars(charResult, intResult);
            cout<<"\nThe result is ";
            for (char i:charResult) {
                cout<<i;
            }
            cout<<"\n";
        } else {
            cout<<"Addition overflow\n";
        }
        
        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}