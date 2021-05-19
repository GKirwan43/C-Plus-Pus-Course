#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

int startHour;
int startMinute;
int startSecond;

vector<string> ftime;
vector<string> stime;
vector<string> ttime;
vector<int> place;
vector<int> finishTime;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void checkTime() {
    for (int j=0;j<place.size();j++) {
        int raceTime=0;
        for (int i=0;i<ttime.size();i++) {
            if (stoi(ttime[i].substr(ttime[i].find("n")+1,ttime[i].find("h")-1))==place[j]) {
                int hour=stoi(ttime[i].substr(ttime[i].find("h")+1,ttime[i].find("m")-1));
                int minute=stoi(ttime[i].substr(ttime[i].find("m")+1,ttime[i].find("s")-1));
                int second=stoi(ttime[i].substr(ttime[i].find("s")+1,ttime[i].length()));
                raceTime=(hour*60*60)+(minute*60)+second;
            }
        }
        if (raceTime<(startHour*60*60)+(startMinute*60)+startSecond+270) {
            cout<<"Racer "<<place[j]<<" may have cheated. His time was faster than 4:30.\n";
        }
    }
}

void checkSensors() {
    for (int j=0;j<place.size();j++) {
        bool fpassed=false;
        bool spassed=false;
        bool tpassed=false;

        for (int i=0;i<ftime.size();i++) {
            if (stoi(ftime[i].substr(ftime[i].find("n")+1,ftime[i].find("h")-1))==place[j]) {
                fpassed=true;
            }
        }

        for (int i=0;i<stime.size();i++) {
            if (stoi(stime[i].substr(stime[i].find("n")+1,stime[i].find("h")-1))==place[j]) {
                spassed=true;
            }
        }

        for (int i=0;i<ttime.size();i++) {
            if (stoi(ttime[i].substr(ttime[i].find("n")+1,ttime[i].find("h")-1))==place[j]) {
                tpassed=true;
            }
        }

        if (!fpassed) {
            cout<<"Racer "<<place[j]<<" may have cheated. He was not recorded at the first sensor.\n";
        }
        if (!spassed) {
            cout<<"Racer "<<place[j]<<" may have cheated. He was not recorded at the second sensor.\n";
        }
        if (!tpassed) {
            cout<<"Racer "<<place[j]<<" may have cheated. He was not recorded at the third sensor.\n";
        }
    }
}

int main() {
    fstream input("input.txt", ios::in);
    string next;

    input>>startHour;
    input>>startMinute;
    input>>startSecond;

    while (!input.eof()) {
        input>>next;
        string statusNum=next.substr(0, 1);
        next.erase(0,2);
        string num=next.substr(0, next.find(","));
        next.erase(0, next.find(",")+1);
        string hour=next;
        input>>next;
        string minute=next;
        input>>next;
        string second=next;
        
        if (statusNum=="0") {
            ftime.push_back("n"+num+" h"+hour+" m"+minute+" s"+second);
        } else if (statusNum=="1") {
            stime.push_back(" n"+num+" h"+hour+" m"+minute+" s"+second);
        } else if (statusNum=="2") {
            ttime.push_back(" n"+num+" h"+hour+" m"+minute+" s"+second);
        }
    }

    for (int i=0;i<ttime.size();i++) {
        place.push_back(stoi(ttime[i].substr(ttime[i].find("n")+1,ttime[i].find("h")-1)));
    }

    checkTime();
    checkSensors();
}