#include <stdio.h>
#include <string.h>
#include "account.h"

#define FILE_NAME "data/accounts.dat"

int hashPin(int pin) {
    return pin * 7 + 13;
}

int accountExists(int accNo) {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Account acc;

    if (!fp) return 0;

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void createAccount() {
    FILE *fp = fopen(FILE_NAME, "ab");
    struct Account acc;

    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("\n--- Create Account ---\n");
    printf("Account No: ");
    scanf("%d", &acc.accNo);

    if (accountExists(acc.accNo)) {
        printf("Account already exists!\n");
        fclose(fp);
        return;
    }

    printf("Name: ");
    scanf(" %[^\n]", acc.name);

    printf("PIN: ");
    scanf("%d", &acc.pin);
    acc.pin = hashPin(acc.pin);

    printf("Deposit: ");
    scanf("%lf", &acc.balance);

    if (acc.balance < 0) {
        printf("Invalid deposit!\n");
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

    if (!fp) {
        printf("File error!\n");
        return -1;
    }

    printf("Account No: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {

            if (!acc.isActive) {
                printf("Account is locked!\n");
                fclose(fp);
                return -1;
            }

            while (attempts < 3) {
                printf("PIN: ");
                scanf("%d", &pin);

                if (hashPin(pin) == acc.pin) {
                    fclose(fp);
                    return accNo;
                }
                attempts++;
                printf("Wrong PIN! Attempts left: %d\n", 3 - attempts);
            }

            acc.isActive = 0;
            fseek(fp, -(long)sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("Account locked due to multiple attempts!\n");
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    printf("Account not found!\n");
    return -1;
}