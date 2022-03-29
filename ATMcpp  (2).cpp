// Shatha_atm.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include<istream>
#include "shathaAtm.h"
using namespace std;
void intromenu();
void MainMenu();
void IsLoggedIn(int, int);
void creatAccount(int, int);
void usrdeposit();
void usrwithdraw();
void seebalance();
void file_check();

ShathaAtm s;

ShathaAtm account[20];
int usrname, usrpass, r = 0, indx = 0;
double balancin;

void file_check() {
    ifstream through;
    through.open("atmdata.txt");
    if (&through) {
        for (int j = 0; j < 20; j++) {
            r += 1;
        }
    }
    else {
        cout << "\n\tErorr,THIS FILE DOES NOT EXIST! " << endl;

    }
}
void intromenu() {
    char input;
    int usnCheck;
    int passCheck;
    int createId;
    int createPass;
    cout << endl;
    cout << "l->Login" << endl;
    cout << "c->Create New Account" << endl;
    cout << "q->Quit" << endl;
    cin >> input;
    switch (input) {
    case 'l':
    case 'L':
        cout << endl << "\n\tPlease enter your user name: " << endl;
        cin >> usnCheck;
        cout << "\n\tPlease enter your password: " << endl;
        cin >> passCheck;
        IsLoggedIn(usnCheck, passCheck); //pass the username and password to the function IsLoggedIn
        break;
    case 'c':
    case 'C':
        cout << endl << "\n\tPlease enter your user name: " << endl;
        cin >> createId;
        cout << "\n\tPlease enter your password: \n\t" << endl;
        cin >> createPass;
        creatAccount(createId, createPass); //pass the username and the password created by the user to the function creatAccount
        break;
    case 'q':
    case 'Q':
        cout << endl << "\n\tYou selected quit!\n\t" << endl;
        exit(0);//exit the program

    default:
        cout << endl << " \n\tINVALID SELLECTION!\n\t " << endl;
        intromenu();
    }
}

void creatAccount(int x, int y) { //a function to creat an account for the user
    int id2 = x, pass2 = y;
    double usrbalance = 0.00;
    for (int l = 0; l < r; l++) {
        if (id2 == account[l].get_usrname() && pass2 == account[l].get_usrpass()) {
            cout << "\n\t USERNAME IS ALREADY TAKEN! \n\t" << endl;
            intromenu();
        }
    }

    account[r].set_usrpas(pass2);
    account[r].set_usrnam(id2);
    account[r].set_balance(usrbalance);
    r++;
    cout << endl;
    cout << "\n\t THANK YOU! YOUR ACCOUNT HAS BEEN CREATEAD! \n\t" << endl;
    intromenu();
}



void IsLoggedIn(int m, int n) {
    int un;
    int pw;
    double balancin = 0.00;
    un = m;
    pw = n;
    cout << " r " << r << endl;
    for (int q = 0; q < r; q++) {
        if (account[q].get_usrname() == un && account[q].get_usrpass() == pw) {
            cout << " \n\tYOU ARE LOGGED IN \n\t" << endl;
            MainMenu();
        }
        else {
            cout << "\n\t WRONG OPPERATION, USER DOES NOT EXIST\n\t " << endl;
            intromenu();
        }
    }

}


void MainMenu() {
    char sellect;
    cout << "\n\t************************************";
    cout << "\n\t*     Welcome to Shatha's ATM      *";
    cout << "\n\t*     d -> Deposit Money           *";
    cout << "\n\t*     w -> Withdraw Money          *";
    cout << "\n\t*     r -> Request Balance         *";
    cout << "\n\t*     q. quit                      *";
    cout << "\n\t*                                  *";
    cout << "\n\t************************************";
    cout << endl;
    cin >> sellect;
    switch (sellect) {
    case'd':
    case'D':
        usrdeposit();
        break;
    case'w':
    case'W':
        usrwithdraw();
        break;
    case'r':
    case'R':
        seebalance();
        break;
    case 'q':
    case'Q':
        s.updatebalance();
        break;
    default:
        cout << "\n\t INVALID SELLECTION! " << endl;
        exit(0); //exit the program
    }

}



void usrdeposit() { //void fun to add to deposit amount to the user's account
    double depositin = 0.00;
    double balancein = s.get_balance();
    cout << "\n\tENTER DEPOSIT AMOUNT : " << "OMR" << endl;
    cin >> depositin;
    cout << "\nYOU HAVE DEPOSIT " << depositin << " OMR SUCCESSFULLY ! " << endl;
    balancein += depositin;
    account[r].set_balance(balancein);
    MainMenu();
}


void usrwithdraw() { //void fun to take out the withdraw amount from the user's account
    double withdrawin = 0.00;
    double balancein = s.get_balance();
    cout << "\n\tENTER WITHDRAW AMOUNT : " << "OMR" << endl;
    cin >> withdrawin;
    if (withdrawin > balancein) { //if the withdraw amount grater than the balance in the user's account
        cout << "\nSORRY YOU DO NOT HAVE ENOGH MONEY TO MAKE THIS TRANSACITION " << endl;
        MainMenu(); //back to the mainmenu
    }
    else {
        balancein -= withdrawin; //subtract thw withdraw amount from the balance
        account[r].set_balance(balancein);
        cout << "\nYOU HAVE WITHDRAW " << withdrawin << "SUCCESSFULLY ! " << endl;
        MainMenu();
    }
}

void seebalance() {
    cout << "\n\nYOUR CURRENT BALANCE : " << s.get_balance() << endl;
    MainMenu();
}

int main()
{
    ShathaAtm s;
    cout << "\n\tWELCOME TO SHATHA'S ATM MACHINE , PLEASE SELLECT AN OPTION:" << endl;
    intromenu();
    return 0;
}
