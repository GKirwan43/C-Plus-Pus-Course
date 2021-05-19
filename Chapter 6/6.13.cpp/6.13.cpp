#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std; 

int main() {
   string fileName;
   string countingString;

   cout<<"Enter file name:\n";
   cin>>fileName;

   fstream input(fileName, ios::in);

   if (!input) {
       cout<<"File not found.\n";
       exit(1);
   }

   int count = -1;

   while(input) {
       input>>countingString;
       count++;
   }

    cout<<"That file contains "<<count<<" words.\n";
}