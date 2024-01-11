#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void login();
void registration();
void forgot();

int main(){

    int c;
    cout <<"\t\t\t____________________________\n\n\n";
    cout <<"\t\t\t  Welcome to Login Page     \n\n\n";
    cout << "\t\t\t_________  Menu  __________\n\n\n";
    cout <<"\t| Press 1 to Login                 |" << endl;
    cout <<"\t| Press 2 to Register              |" << endl;
    cout <<"\t| Press 3 to forgot your password  |" << endl;
    cout <<"\t| Press 4 to Exit                  |" << endl;
    cout <<"\n\t\t\t Please enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();

    case 4:
        cout << "\t\t\t Thankyou! \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Please select from the options given above\n" << endl;
        main();
    }
}

void login(){

    int count;
    string userid, password, id, pass;
    system("cls"); 
    cout << "\t\t\t Please enter username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userid;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream read("records.txt");

    while(read >> id >> pass){
        if(id == userid && pass == password){
            count = 1;
            system ("cls");
        }
    }
    read.close();
    if(count == 1){
        cout << userid << "\n Your login is successfull. \n Thanks for loggin in ! \n";
        main();
    }
    else{
        cout << "\nLogin Error \n Please check your username and password\n";
        main();
    }
}

void registration(){
    string ruserid,rpassword,rid,rpass;
    system("cls");
    cout << "\t\t\t Enter the username: " ;
    cin >> ruserid;
    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;

    ofstream write("records.txt", ios::app);
    write << ruserid << " " << rpassword << endl;
    system("cls");

    cout << "\t\t\t Registration is successfull ! \n";
    main();
}

void forgot(){

    int option;
    system("cls");
    cout << "\t\t\t You forget the password? No worries \n";
    cout << "Press 1 to search your id by username: " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;
    switch (option)
    {
    case 1:{
        int count = 0;
        string suserid, sid, spass;
        cout << "\n\t\t\tEnter the username which you remember: ";
        cin >> suserid;

        ifstream check("records.txt");
        while(check >> sid >> spass){
            if(sid == suserid){
                count = 1;
            }
        }
        check.close();
        if(count == 1){
            cout << "\n\n Your account is found \n";
            cout << "\n\n Your password is: " << spass;
            main();
        }else{
            cout << "\n\t Sorry! Your account is not found\n";

        }
    }
        
    break;
    
    case 2:
        {
            main();
        }
        break;
    default:
        cout << "\t\t\t Wrong choice ! Please try again " << endl;
        forgot();
    }
}