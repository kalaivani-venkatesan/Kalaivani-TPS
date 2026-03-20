#include <stdio.h>
#include <string.h>
#include "account.h"

#define FILE_NAME "data/accounts.dat"

int hashPin(int pin) {
    return pin * 7 + 13;
}

void createAccount() {
    FILE *fp = fopen(FILE_NAME, "ab");
    struct Account acc;

    if (!fp) {
        printf("❌ File error!\n");
        return;
    }

    printf("\n--- Create New Account ---\n");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);

    printf("Set 4-digit PIN: ");
    scanf("%d", &acc.pin);
    acc.pin = hashPin(acc.pin);

    printf("Initial Deposit: ");
    scanf("%lf", &acc.balance);

    if (acc.balance < 0) {
        printf("❌ Invalid deposit!\n");
        fclose(fp);
        return;
    }

    acc.isActive = 1;
    acc.dailyWithdraw = 0;

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("✅ Account Created Successfully!\n");
}

int login() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    struct Account acc;
    int accNo, pin, attempts = 0;

    printf("\n--- Login ---\n");
    printf("Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {

            if (!acc.isActive) {
                printf("❌ Account Locked!\n");
                return -1;
            }

            while (attempts < 3) {
                printf("Enter PIN: ");
                scanf("%d", &pin);

                if (hashPin(pin) == acc.pin) {
                    printf("✅ Login Successful!\n");
                    fclose(fp);
                    return accNo;
                }

                attempts++;
                printf("❌ Wrong PIN! Attempts left: %d\n", 3 - attempts);
            }

            acc.isActive = 0;
            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("🔒 Account Locked!\n");
            fclose(fp);
            return -1;
        }
    }

    printf("❌ Account not found!\n");
    fclose(fp);
    return -1;
}