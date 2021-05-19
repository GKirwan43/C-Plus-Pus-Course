#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decrypt(string message, int key) {
    string returnVal;

    for(int i=0;i<message.size();i++) {
        if (message[i]<32) {
            returnVal+=message[i]-key;
        } else {
            returnVal+=message[i]+95-key;
            if (message[i]+key<127) {
                returnVal+=message[i]-key;
            }
        }
    }

    return returnVal;
}

int main()
{
    for (int i=0;i<100;i++) {
        cout<<decrypt(":mmZ\\dxZmx]Zpgy", i+1)<<"\n";
    }
}