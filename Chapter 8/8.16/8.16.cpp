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

void finishPlace(int response) {
    for (int i=0;i<ttime.size();i++) {
        int hour=stoi(ttime[i].substr(ttime[i].find("h")+1,ttime[i].find("m")-1));
        int minute=stoi(ttime[i].substr(ttime[i].find("m")+1,ttime[i].find("s")-1));
        int second=stoi(ttime[i].substr(ttime[i].find("s")+1,ttime[i].length()));
        place.push_back(stoi(ttime[i].substr(ttime[i].find("n")+1,ttime[i].find("h")-1)));
        finishTime.push_back((hour*60*60)+(minute*60)+second);
    }

    int n = finishTime.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (finishTime[j] > finishTime[j+1]) {
                swap(&finishTime[j], &finishTime[j+1]);
                swap(&place[j], &place[j+1]);
            }
        }
    }

    for (int i=0; i<place.size(); i++) {
        if (place[i]==response) {
            cout<<response<<"'s overall place is "<<i+1<<".\n";
        }
    }
}

void split(int response) {
    int sensor1;
    int sensor2;
    int sensor3;

    for (int i=0;i<ftime.size();i++) {
        if (stoi(ftime[i].substr(ftime[i].find("n")+1,ftime[i].find("h")-1))==response) {
            int hour=stoi(ftime[i].substr(ftime[i].find("h")+1,ftime[i].find("m")-1));
            int minute=stoi(ftime[i].substr(ftime[i].find("m")+1,ftime[i].find("s")-1));
            int second=stoi(ftime[i].substr(ftime[i].find("s")+1,ftime[i].length()));
            sensor1=(hour*60*60)+(minute*60)+second;
        }
    }

    for (int i=0;i<stime.size();i++) {
        if (stoi(stime[i].substr(stime[i].find("n")+1,stime[i].find("h")-1))==response) {
            int hour=stoi(stime[i].substr(stime[i].find("h")+1,stime[i].find("m")-1));
            int minute=stoi(stime[i].substr(stime[i].find("m")+1,stime[i].find("s")-1));
            int second=stoi(stime[i].substr(stime[i].find("s")+1,stime[i].length()));
            sensor2=(hour*60*60)+(minute*60)+second;
        }
    }

    for (int i=0;i<ttime.size();i++) {
        if (stoi(ttime[i].substr(ttime[i].find("n")+1,ttime[i].find("h")-1))==response) {
            int hour=stoi(ttime[i].substr(ttime[i].find("h")+1,ttime[i].find("m")-1));
            int minute=stoi(ttime[i].substr(ttime[i].find("m")+1,ttime[i].find("s")-1));
            int second=stoi(ttime[i].substr(ttime[i].find("s")+1,ttime[i].length()));
            sensor3=(hour*60*60)+(minute*60)+second;
        }
    }

    cout<<"Time between sensor 1 and sensor 2 is "<<(sensor2-sensor1)/60.0<<" minutes.\n";
    cout<<"Time between sensor 2 and sensor 3 is "<<(sensor3-sensor2)/60.0<<" minutes.\n";
}

void overallRaceTime() {
    int raceTime=0;
    int index=0;
    int totalTime=(startHour*60*60)+(startMinute*60)+startSecond;
    for (int i=0;i<ttime.size();i++) {
        int hour=stoi(ttime[i].substr(ttime[i].find("h")+1,ttime[i].find("m")-1));
        int minute=stoi(ttime[i].substr(ttime[i].find("m")+1,ttime[i].find("s")-1));
        int second=stoi(ttime[i].substr(ttime[i].find("s")+1,ttime[i].length()));
        int finishedTime=(hour*60*60)+(minute*60)+second;
        if (finishedTime>raceTime) {
            raceTime=finishedTime;
            index=i;
        }
    }

    cout<<"Overall race time is "<<(raceTime-totalTime)/60<<" minutes.\n";
    cout<<"Overall race pace is "<<13.1/((raceTime-totalTime)/60)<<" miles per minute.\n";
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

    int response;
    cout<<"Enter a race number:\n";
    cin>>response;

    finishPlace(response);
    split(response);
    overallRaceTime();
}