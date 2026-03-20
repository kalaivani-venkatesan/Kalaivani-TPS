#include <stdio.h>
#include "admin.h"

#define ADMIN_PASS 1234

void adminPanel() {
    int pass, choice;

    printf("\n--- Admin Login ---\n");
    printf("Enter Password: ");
    scanf("%d", &pass);

    if (pass != ADMIN_PASS) {
        printf("❌ Access Denied!\n");
        return;
    }

    do {
        printf("\n========== ADMIN PANEL ==========\n");
        printf("1. Export Accounts\n");
        printf("2. Update Account\n");
        printf("3. Add Account\n");
        printf("4. Delete Account\n");
        printf("5. Edit Account\n");
        printf("6. Search Account\n");
        printf("7. List Accounts\n");
        printf("8. Statistics\n");
        printf("9. Search by Name\n");
        printf("11. Exit\n");
        printf("=================================\n");
        printf("Choice: ");
        scanf("%d", &choice);

        // (Call previously given functions here)

    } while (choice != 11);
}