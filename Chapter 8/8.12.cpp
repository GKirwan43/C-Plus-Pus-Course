#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string convert(string& time, string& hour, string& minute) {
    hour=time.substr(0, time.find(":"));
    time.erase(0, time.find(":")+1);

    minute=time.substr(0, time.find(" "));
    time.erase(0, time.find(" ")+1);

    if (time=="PM") {
        int newHour=stoi(hour)+12;
        if (newHour==24) {
            hour="12";
        } else {
            hour=to_string(newHour);
        }
    }
    if (time=="AM") {
        int newHour=stoi(hour);
        if (newHour==12) {
            hour="00";
        } else if (newHour<10) {
            hour="0"+to_string(newHour);
        } else {
            hour=to_string(newHour);
        }
    }

    return "Military time is: "+hour+""+minute+" hours\n";
}

int main() {
    string time;
    string hour;
    string minute;

    cout<<"Time? (HH:MM AM/PM)\n";
    getline(cin,time);

    cout<<convert(time, hour, minute);
}