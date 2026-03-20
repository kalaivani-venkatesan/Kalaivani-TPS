#include <stdio.h>
#include "transaction.h"
#include "account.h"
#include "utils.h"

#define FILE_NAME "data/accounts.dat"
#define DAILY_LIMIT 10000

void deposit(int accNo) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    struct Account acc;
    double amt;

    printf("\n--- Deposit ---\n");
    printf("Enter Amount: ");
    scanf("%lf", &amt);

    if (amt <= 0) {
        printf("❌ Invalid amount!\n");
        return;
    }

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            acc.balance += amt;

            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            logTransaction(accNo, "DEPOSIT", amt);
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

    printf("\n--- Withdraw ---\n");
    printf("Enter Amount: ");
    scanf("%lf", &amt);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {

            if (amt > acc.balance) {
                printf("❌ Insufficient Balance!\n");
                break;
            }

            if (acc.dailyWithdraw + amt > DAILY_LIMIT) {
                printf("❌ Daily Limit Exceeded!\n");
                break;
            }

            acc.balance -= amt;
            acc.dailyWithdraw += amt;

            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            logTransaction(accNo, "WITHDRAW", amt);
            printf("✅ Withdraw Successful!\n");
            break;
        }
    }
    fclose(fp);
}