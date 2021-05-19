#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std; 

double maxVal(double n1, double n2, double n3, double n4) {
    if (n1>=n2&&n1>n3&&n1>=n4) {
        return n1;
    }
    if (n2>=n1&&n2>=n3&&n2>=n4) {
        return n2;
    }
    if (n3>=n1&&n3>=n2&&n3>=n4) {
        return n3;
    }
    return n4;
}

void scale(double& n1, double& n2, double& n3, double& n4) {
    double max = maxVal(n1, n2, n3, n4);
    n1/=max;
    n2/=max;
    n3/=max;
    n4/=max;
    n1*=400;
    n2*=400;
    n3*=400;
    n4*=400;
    n1=500-n1;
    n2=500-n2;
    n3=500-n3;
    n4=500-n4;
}

int main() {
    fstream output("output.svg", ios::out);

    double num1=0;
    double num2=0;
    double num3=0;
    double num4=0;

    cout<<"Enter four integers:\n";
    cin>>num1>>num2>>num3>>num4;

    scale(num1,num2,num3,num4);

    string before = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg width=\"500\" height=\"500\"\nxmlns=\"http://www.w3.org/2000/svg\">\n";
    string after = "</svg>";

    string xAxis = "<line x1=\"50\" y1=\"500\" x2=\"500\" y2=\"500\"\nstyle=\"stroke:black;stroke-width:2\"/>";
    string yAxis = "<line x1=\"50\" y1=\"500\" x2=\"50\" y2=\"50\"\nstyle=\"stroke:black;stroke-width:2\"/>";

    string rect1 = "<line x1=\"90\" y1=\"";
    string rect1_end = "\" x2=\"90\" y2=\"500\"\nstyle=\"stroke:black;stroke-width:20\"/>";
    string rect2 = "<line x1=\"150\" y1=\"";
    string rect2_end = "\" x2=\"150\" y2=\"500\"\nstyle=\"stroke:black;stroke-width:20\"/>";
    string rect3 = "<line x1=\"210\" y1=\"";
    string rect3_end = "\" x2=\"210\" y2=\"500\"\nstyle=\"stroke:black;stroke-width:20\"/>";
    string rect4 = "<line x1=\"270\" y1=\"";
    string rect4_end = "\" x2=\"270\" y2=\"500\"\nstyle=\"stroke:black;stroke-width:20\"/>";

    output<<before<<xAxis<<yAxis<<rect1<<num1<<rect1_end<<rect2<<num2<<rect2_end<<rect3<<num3<<rect3_end<<rect4<<num4<<rect4_end<<after;
}