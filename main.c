#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "transaction.h"
#include "admin.h"

void clearScreen() {
    system("cls"); // use "clear" for Linux/Mac
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

int main() {
    int choice, accNo;

    while (1) {
        clearScreen();

        printf("\n====================================\n");
        printf("        BANKING SYSTEM\n");
        printf("====================================\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Admin Panel\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                pauseScreen();
                break;

            case 2:
                accNo = login();
                if (accNo != -1) {
                    int ch;
                    do {
                        clearScreen();
                        printf("\n====== USER DASHBOARD ======\n");
                        printf("1. Deposit\n");
                        printf("2. Withdraw\n");
                        printf("3. Transfer\n");
                        printf("4. Check Balance\n");
                        printf("5. Transaction History\n");
                        printf("6. Logout\n");
                        printf("---------------------------\n");
                        printf("Enter Choice: ");
                        scanf("%d", &ch);

                        switch (ch) {
                            case 1: deposit(accNo); break;
                            case 2: withdraw(accNo); break;
                            case 3: transfer(accNo); break;
                            case 4: showBalance(accNo); break;
                            case 5: showTransactions(accNo); break;
                        }

                        if (ch != 6) pauseScreen();

                    } while (ch != 6);
                }
                break;

            case 3:
                adminPanel();
                break;

            case 4:
                printf("\nThank you for using our banking system!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                pauseScreen();
        }
    }
}