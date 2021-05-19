#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int num7;
    int num8;
    int num9;
    int num10;

    cout << "Enter 10 whole numbers:\n";
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10;

    int greater_sum;
    if (num1 >0) greater_sum+=num1;
    if (num2 > 0) greater_sum+=num2;
    if (num3 > 0) greater_sum+=num3;
    if (num4 > 0) greater_sum+=num4;
    if (num5 > 0) greater_sum+=num5;
    if (num6 > 0) greater_sum+=num6;
    if (num7 > 0) greater_sum+=num7;
    if (num8 > 0) greater_sum+=num8;
    if (num9 > 0) greater_sum+=num9;
    if (num10 > 0) greater_sum+=num10;

    int less_sum;
    if (num1 < 0) less_sum+=num1;
    if (num2 < 0) less_sum+=num2;
    if (num3 < 0) less_sum+=num3;
    if (num4 < 0) less_sum+=num4;
    if (num5 < 0) less_sum+=num5;
    if (num6 < 0) less_sum+=num6;
    if (num7 < 0) less_sum+=num7;
    if (num8 < 0) less_sum+=num8;
    if (num9 < 0) less_sum+=num9;
    if (num10 < 0) less_sum+=num10;

    if (less_sum) {
        cout << "\n\nSum of numbers less than zero is " << less_sum << ".\n";
    } else {
        cout << "\n\nSum of numbers less than zero is 0.\n";
    }

    if (greater_sum) {
        cout << "Sum of numbers greater than zero is " << greater_sum << "\n";
    } else {
        cout << "\n\nSum of numbers greater than zero is 0.\n";
    }

    cout << "\nThe sum of all numbers is " << num1+num2+num3+num4+num5+num6+num7+num8+num9+num10 << ".\n";

    return 0;
}