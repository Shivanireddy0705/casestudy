#include <stdio.h>
#include <string.h>
#include "customer.h"

int searchCustomerByName(const char *name, struct Customer *customer) {
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL) {
        return 0;
    }

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        char storedName[50];
        char storedAddress[100];
        char storedPhone[20];
        sscanf(line, "%[^,],%[^,],%s", storedName, storedAddress, storedPhone);

        if (strcmp(name, storedName) == 0) {
            strcpy(customer->name, storedName);
            strcpy(customer->address, storedAddress);
            strcpy(customer->phone, storedPhone);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void storeCustomerName(const char *name) {
    FILE *file = fopen("current_customer.txt", "w");
    if (file == NULL) {
        return;
    }

    fprintf(file, "%s", name);
    fclose(file);
}