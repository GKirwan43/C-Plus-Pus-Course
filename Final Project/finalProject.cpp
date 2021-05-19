#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Arrays of criteria that need to be met for password.
string mustContainUpperLetterArr[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string mustContainLowerLetterArr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
string mustContainNumberArr[] = {"0","1","2","3","4","5","6","7","8","9"};
string mustContainSymbolArr[] = {"@","!","@","#","$","%","^","&","*","(",")"};

vector<string> usernames;
vector<string> passwords;

bool loggedIn=false;

//Checks password criteria with arrays above.
bool check(string password, string *array, int length) {
    bool meetsCriteria=false;
    for (int i=0;i<length;i++) {
        if (password.find(array[i])<password.length()) {
           meetsCriteria=true;
        }
    }
    return meetsCriteria;
}

//Replaces password text with *.
string censor(string password) {
    string censoredPassword;
    for (int i=0; i<password.length(); i++) {
        censoredPassword+="*";
    }
    return censoredPassword;
}

//Updates vectors above to reflect input file.
void updateAccounts() {
    usernames.clear();
    passwords.clear();

    fstream input("usernamesPasswords.txt", ios::in);

    while (!input.eof()) {
        string username;
        input>>username;
        usernames.push_back(username);
        string password;
        input>>password;
        passwords.push_back(password);
    }

    input.close();
}


//Prompts user to login.
void login() {
    string username;
    string password;
    cout<<"\nPlease enter a username:\n";
    cin>>username;
    cout<<"\nPlease enter a password:\n";
    cin>>password;

    bool usernameExists=false;
    int index;

    for (int i=0; i<usernames.size(); i++) {
        if (usernames[i]==username) {
            usernameExists=true;
            index=i;
        }
    }

    if (usernameExists&&passwords[index]==password) {
        loggedIn=true;
        cout<<"\nWelcome "<<usernames[index]<<"! You have logged in.\n";
    } else {
        cout<<"\nUsername or Password is incorrect.\n";
    }
}

//Prompts user to sign up.
void signup() {
    string username;
    string password;
    cout<<"\nPlease enter a username:\n";
    cin>>username;

    bool usernameExists=false;
    for (int i=0;i<usernames.size();i++) {
        if (usernames[i]==username) {
            usernameExists=true;
        }
    }

    if (usernameExists) {
        cout<<"\nThat username is taken.\n";
    } else {
        cout<<"\nPlease enter a password that meets the criteria below:\n";
        cout<<"- Must contain atleast one upper case letter.\n";
        cout<<"- Must contain atleast one lower case letter.\n";
        cout<<"- Must contain atleast one number.\n";
        cout<<"- Must contain atleast one of these symbols: !@$%^&*()\n";
        cout<<"\nPlease enter a password:\n";
        cin>>password;

        cout<<"\n";

        bool passed=true;
        if (!check(password, mustContainUpperLetterArr, 26)) {
            cout<<"Password does not contain an upper case letter.\n";
            passed=false;
        }
        if (!check(password, mustContainLowerLetterArr, 26)) {
            cout<<"Password does not contain an lower case letter.\n";
            passed=false;
        }
        if (!check(password, mustContainNumberArr, 10)) {
            cout<<"Password does not contain a number.\n";
            passed=false;
        }
        if (!check(password, mustContainSymbolArr, 10)) {
            cout<<"Password does not contain a symbol.\n";
            passed=false;
        }

        if (passed) {
            fstream output("usernamesPasswords.txt", ios::app);
            output<<username<<" "<<password<<"\n";
            output.close();
            cout<<"Account created:\n";
            cout<<"Username: "<<username<<"\n";
            cout<<"Password: "<<censor(password)<<"\n";
        } else {
            cout<<"Account not created.\n";
        }
    }
}

//Loops outputs depending on the login state.
int main() {
    while (true) {
        int response;
        
        updateAccounts();

        cout<<"What would you like to do?\n";

        if (loggedIn) {
            cout<<"[1] Logout\n";
            cout<<"[2] Exit\n";

            cin>>response;

            if (response==1) {
                cout<<"\nYou have logged out.\n";
                loggedIn=false;
            } else if (response==2) {
                break;
            } else {
                cout<<"\nThat is not an option.\n";
            }
            cout<<"\n";
        } else {
            cout<<"[1] Login\n";
            cout<<"[2] Sign up\n";
            cout<<"[3] Exit\n";

            cin>>response;

            if (response==1) {
                login();
            } else if (response==2) {
                signup();
            } else if (response==3) {
                break;
            } else {
                cout<<"\nThat is not an option.\n";
            }
            cout<<"\n";
        }
    }
}