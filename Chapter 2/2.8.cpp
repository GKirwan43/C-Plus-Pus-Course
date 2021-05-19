#include <iostream>
using namespace std;

int main()
{
    double cost = 1000;
    double interest = 0;
    int months = 0;

    while (cost>0)
    {
        interest+=.015*cost;
        cost=(1.015*cost)-50;
        months++;
    }

    cout << "It will take ";
    cout << months;
    cout << " months to pay off the debt and total interest is $";
    cout.precision(2);
    cout << fixed << interest << endl;

    return 0;
}