#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account {
    int accNo;
    char name[50];
    int pin;
    double balance;
    int isActive;
    double dailyWithdraw;
};

void createAccount();
int login();

#endif