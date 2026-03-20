#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"

void logTransaction(int accNo, char type[], double amt) {
    FILE *tf = fopen("data/transactions.dat", "ab");

    struct {
        int accNo;
        char type[20];
        double amount;
        char time[30];
    } t;

    time_t now = time(NULL);
    strftime(t.time, sizeof(t.time), "%Y-%m-%d %H:%M:%S", localtime(&now));

    t.accNo = accNo;
    strcpy(t.type, type);
    t.amount = amt;

    fwrite(&t, sizeof(t), 1, tf);
    fclose(tf);
}

void generateReceipt(int accNo, char type[], double amt) {
    FILE *rf = fopen("data/receipts.txt", "a");
    fprintf(rf, "Acc:%d | %s | %.2lf\n", accNo, type, amt);
    fclose(rf);
}