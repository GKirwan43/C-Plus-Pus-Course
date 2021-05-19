#include <iostream>
#include <string>
using namespace std;

void delete_repeats(char letters[], int& size)
{
    int k = 0;

    for(int i = 0; i < size; ++i)
    {
        bool found = false;

        for(int j = 0; j < k; ++j) {
            if(letters[i] == letters[j]) {
                found = true;
            }
        }

        if(!found) {
            letters[k++] = letters[i];
        }
    }

    size = k;
}

int main()
{
    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'b';
    a[3] = 'b';
    int size = 4;
    delete_repeats(a, size);

    cout<<"After test, the values are:\n{";
    for (int i=0; i<size; i++) {
        if (i!=0) {
            cout <<", ";
        }
        cout<<a[i];
    }
    cout<<"}\n";
}