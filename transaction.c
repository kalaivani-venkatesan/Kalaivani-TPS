#include <stdio.h>
#include <string.h>
#include "transaction.h"
#include "account.h"
#include "utils.h"

#define FILE_NAME "data/accounts.dat"
#define DAILY_LIMIT 10000

void deposit(int accNo) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    struct Account acc;
    double amt;

    if (!fp) return;

    printf("Amount: ");
    scanf("%lf", &amt);

    if (amt <= 0) {
        printf("Invalid amount!\n");
        fclose(fp);
        return;
    }

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            acc.balance += amt;
            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            logTransaction(accNo, "DEPOSIT", amt);
            generateReceipt(accNo, "DEPOSIT", amt);

            printf("✅ Deposit Successful!\n");
            break;
        }
    }
    fclose(fp);
}

void withdraw(int accNo) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    struct Account acc;
    double amt;

    if (!fp) return;

    printf("Amount: ");
    scanf("%lf", &amt);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {

            if (amt <= 0 || amt > acc.balance) {
                printf("Invalid / Insufficient!\n");
                break;
            }

            if (acc.dailyWithdraw + amt > DAILY_LIMIT) {
                printf("Daily limit exceeded!\n");
                break;
            }

            acc.balance -= amt;
            acc.dailyWithdraw += amt;

            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            logTransaction(accNo, "WITHDRAW", amt);
            generateReceipt(accNo, "WITHDRAW", amt);

            printf("✅ Withdraw Successful!\n");
            break;
        }
    }
    fclose(fp);
}
void transfer(int fromAcc) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    struct Account acc;
    int toAcc, foundTo = 0;
    double amt;

    if (!fp) return;

    printf("To Account: ");
    scanf("%d", &toAcc);

    if (toAcc == fromAcc) {
        printf("Cannot transfer to same account!\n");
        fclose(fp);
        return;
    }

    printf("Amount: ");
    scanf("%lf", &amt);

    if (amt <= 0) {
        printf("Invalid amount!\n");
        fclose(fp);
        return;
    }

    // Deduct sender
    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == fromAcc) {
            if (acc.balance < amt) {
                printf("Insufficient balance!\n");
                fclose(fp);
                return;
            }

            acc.balance -= amt;
            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            break;
        }
    }

    rewind(fp);

    // Add receiver
    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == toAcc) {
            acc.balance += amt;
            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            foundTo = 1;
            break;
        }
    }

    fclose(fp);

    if (!foundTo) {
        printf("Receiver not found!\n");
        return;
    }

    logTransaction(fromAcc, "TRANSFER_OUT", amt);
    logTransaction(toAcc, "TRANSFER_IN", amt);

    generateReceipt(fromAcc, "TRANSFER", amt);

    printf("✅ Transfer Successful!\n");
}

void showBalance(int accNo) {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Account acc;

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Balance: %.2lf\n", acc.balance);
            break;
        }
    }
    fclose(fp);
}

void showTransactions(int accNo) {
    FILE *tf = fopen("data/transactions.dat", "rb");
    struct {
        int accNo;
        char type[20];
        double amount;
        char time[30];
    } t;

    while (fread(&t, sizeof(t), 1, tf)) {
        if (t.accNo == accNo)
            printf("%s | %.2lf | %s\n", t.type, t.amount, t.time);
    }
    fclose(tf);
}