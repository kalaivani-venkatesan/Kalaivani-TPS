#include <stdio.h>
#include "admin.h"
#include "account.h"

#define FILE_NAME "data/accounts.dat"
#define ADMIN_PASS 1234

void adminPanel() {
    int pass;
    printf("Admin Password: ");
    scanf("%d", &pass);

    if (pass != ADMIN_PASS) {
        printf("Access Denied!\n");
        return;
    }

    FILE *fp = fopen(FILE_NAME, "rb");
    struct Account acc;

    printf("\n--- All Accounts ---\n");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("%d | %s | %.2lf\n", acc.accNo, acc.name, acc.balance);
    }

    fclose(fp);
}