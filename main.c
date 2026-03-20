#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "transaction.h"
#include "admin.h"

int main() {
    int choice, accNo;

    while (1) {
        printf("\n====== BANK SYSTEM ======\n");
        printf("1. Create Account\n2. Login\n3. Admin Panel\n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                accNo = login();
                if (accNo != -1) {
                    int ch;
                    do {
                        printf("\n1.Deposit 2.Withdraw 3.Transfer 4.Balance 5.History 6.Logout\n");
                        scanf("%d", &ch);

                        switch (ch) {
                            case 1: deposit(accNo); break;
                            case 2: withdraw(accNo); break;
                            case 3: transfer(accNo); break;
                            case 4: showBalance(accNo); break;
                            case 5: showTransactions(accNo); break;
                        }
                    } while (ch != 6);
                }
                break;

            case 3:
                adminPanel();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}