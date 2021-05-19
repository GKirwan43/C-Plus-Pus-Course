#include <iostream>
using namespace std;

double hatSize(double weight, double height) {
    return (weight/height)*2.9;
}

double jacketSize(double weight, double height, double age) {
    double jacketSize;
    double initJacketSize;
    int posDif;
    if (age > 30) {
        posDif=age-30;
        initJacketSize=(height*weight)/288;
        jacketSize=initJacketSize+.125*(posDif/10);
    }
    return jacketSize;
}

double waistSize(double weight, double age) {
    double waistSizeNum;
    double initWaistSize;
    int posDif;
    if (age <= 28) {
        waistSizeNum = weight/5.7;
    }
    else
    {
        posDif=age-28;
        initWaistSize=weight/5.7;
        waistSizeNum=initWaistSize+.1*floor(posDif/2);
    }
    return waistSizeNum;
}

int main()
{
    while (true) {
        string response;
        double height;
        double weight;
        double age;

        cout << "Height? (Inches)\n";
        cin >> height;
        cout << "Weight? (Pounds)\n";
        cin >> weight;
        cout << "Age?\n";
        cin >> age;

        cout << "Hat Size: " << hatSize(weight, height) << ".\n";
        cout << "Jacket Size: " << jacketSize(weight, height, age) << ".\n";
        cout << "Waist Size: " << waistSize(weight, age) << ".\n";

        cout << "Would you like to go again? (Yes or No)\n";
        cin >> response;
        if (response == "No" || response == "no") {
            break;
        }
    }
}