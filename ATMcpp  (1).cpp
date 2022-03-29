
//  Shatha.cpp
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include<istream>
#include "ShathaAtm.h"
using namespace std;

ShathaAtm::ShathaAtm() {
    usrusername = 0;
    usrpass = 0;
    usrbalance = 0.00;
}
void ShathaAtm::set_balance(double balance1) {
    usrbalance = balance1;
}


double ShathaAtm::get_balance() {
    return usrbalance;
}
void  ShathaAtm::set_usrnam(int p) {
    usrusername = p;
};
void  ShathaAtm::set_usrpas(int c) {
    usrpass = c;
}
int  ShathaAtm::get_usrname() {
    return usrusername;
}

int ShathaAtm::get_usrpass() {
    return usrpass;
}

void  ShathaAtm::updatebalance() { //void function to return the user's current balance in his account
    int un1, pw1;
    un1 = get_usrname();
    pw1 = get_usrpass();
    int un;
    int pw;
    double balancein = 0.00;
    fstream wri;
    wri.open("atmdata.txt", ios::in); //Open file for writing
    ofstream scan;
    scan.open("atmdata.txt"); //Open file for reading 
    while (wri >> un >> pw >> balancein) {
        if (un1 != un) {
            scan << un << " " << pw << " " << balancein << endl;
        }
    }
    wri.close();
    scan.close();
    remove("atmdata.txt"); //delete the atmdata file
    rename("atmdata2.txt", "atmdata.txt"); //rename the atmdata file

    wri.open("atmdata.txt", ios::out | ios::app);//Append the data to the end of the file
    wri << un1 << " " << pw1 << " " << get_balance() << endl; //add the values to the file atmdata
    wri.close();
}
