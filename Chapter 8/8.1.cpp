#include <iostream>
#include<cstring>
using namespace std;

int main()
{ 
    char arr[100];
    string str;

    cout<<"Enter sentence:\n";

    int count=0;
    char next;
    char last;

    while (next!='\n') {
        cin.get(next);
        if (next!='\n') {
            if (last!=' ' || next!=' ') {
                arr[count]=next;
                last=next;
            }
            count++;
        }
    }

    for (int i=0;i<count;i++) {
        if (i==0) {
            cout<<(char)toupper(arr[i]);
        } else {
            cout<<(char)tolower(arr[i]);
        }
        if (i==count-1&&arr[i]!='.') {
            cout<<".";
        }
    }
    
    cout<<"\n";
}