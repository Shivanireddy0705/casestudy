#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "login.h"

void registerUser(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Failed to open users file.\n");
        return;
    }

    fprintf(file, "%s,%s\n", username, password);
    fclose(file);
    printf("User registered successfully.\n");
}

bool isUserRegistered(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return false;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char storedUsername[50];
        char storedPassword[50];
        sscanf(line, "%[^,],%s", storedUsername, storedPassword);

        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}