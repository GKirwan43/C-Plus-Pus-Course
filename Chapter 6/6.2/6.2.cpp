#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void calculate(istream& infile, ostream& outfile) {
    char fname[20];
    char lname[20];
    int grades;
    int sum=0;

    while(!infile.eof())
    {
        infile>>lname;
        infile>>fname;
        outfile<<lname<<" "<<fname<<" ";
        sum=0;
        for(int i=0;i<10;i++) {
            infile>>grades;
            outfile<<grades<<" ";
            sum+=grades;
        }
        outfile<<double(sum/10.0)<<"\n";
    }
}

int main()
{
    fstream infile("input.dat",ios::in);
    fstream outfile("output.dat",ios::out);

    calculate(infile, outfile);

    infile.close();
    outfile.close();
}