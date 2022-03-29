#pragma once

#ifndef shatha_h
#define shatha_h
class ShathaAtm {
private:
    int usrusername;
    int usrpass;
    double usrbalance = 0.00; //intial value of balance 
public:
    ShathaAtm();
    void set_balance(double); //void fun to set the balance
    double get_balance(); //void fun to get the balance
    void set_usrnam(int); //void fun to set the user's username
    int get_usrname();    //void fun to get the user's username
    void set_usrpas(int); //void fun to set the user's password
    int get_usrpass();    //void fun to get the user's password
    void updatebalance();//void fun to update the user's balance

};


#endif /* shatha_h */
