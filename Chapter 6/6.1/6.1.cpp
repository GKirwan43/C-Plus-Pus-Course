#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
 
int main()
{
 
    fstream input("input.dat", ios::in);
    fstream output("output.dat", ios::out);

    char next;
    string temp;
    while (input.get(next)) {
        temp+=next;
    }

    string response;
    int pos = temp.find("#N#");    

    cout << "Enter name:\n";
    cin >> response;
    
    temp.replace(pos, pos+3, response);

    output << temp;
    

    input.close();
    output.close();

}