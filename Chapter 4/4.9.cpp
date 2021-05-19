#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int team1 = 0;
int team2 = 0;
int team3 = 0;
int team4 = 0;

string convertToString(int number) {
    if (number==4) {
        return "Last place";
    } else if (number==3) {
        return "Second-to-last";
    } else if (number==2) {
        return "Third-to-last";
    } else if (number==1) {
        return "Fourth-to-last";
    }
    return "";
}

int selectTeam(int team1, int team2,int team3, int team4)
{
    int selectedBall = 0;
    int counter = 1;
    while(counter>0) {
        counter = 0;
        selectedBall = rand()%40+1;

        if (team1!=0&&selectedBall<=20) counter++;
        if (team2!=0&&selectedBall>20 && selectedBall<=30)counter++;
        if (team3!=0&&selectedBall>30 && selectedBall<=36)counter++;
        if (team4!=0&&selectedBall>36)counter++;
    }

    if (selectedBall<=20) return 1;
    else if (selectedBall>20 && selectedBall<=30) return 2;
    else if (selectedBall>30 && selectedBall<=36) return 3;
    else return 4;
}

void changeState(int pick) {
    if (pick==1) {
        team1=1;
    } else if (pick==2) {
        team2=1;
    } else if (pick==3) {
        team3=1;
    } else if (pick==4) {
        team4=1;
    }
    return;
}



int main() {
    srand(time(0));

    int firstPick = 0;
    int secondPick = 0;
    int thirdPick = 0;
    int fourthPick = 0;

    firstPick= selectTeam(team1, team2, team3, team4);
    changeState(firstPick);
    secondPick= selectTeam(team1, team2, team3, team4);
    changeState(secondPick);
    thirdPick= selectTeam(team1, team2, team3, team4);
    changeState(thirdPick);
    fourthPick= selectTeam(team1, team2, team3, team4);

    cout << convertToString(firstPick) << " Picks 1\n";
    cout << convertToString(secondPick) << " Picks 2\n";
    cout << convertToString(thirdPick) << " Picks 3\n";
    cout << convertToString(fourthPick) << " Picks 4\n";
    return 0;
}