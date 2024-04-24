#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_CUSTOMERS 1000
#define MAX_CUSTOMER_NAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User* users[MAX_USERS];
int num_users = 0;

typedef struct {
    char name[MAX_CUSTOMER_NAME_LENGTH];
    double balance;
} Customer;

Customer* customers[MAX_CUSTOMERS];
int num_customers = 0;

void register_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User* new_user = (User*)malloc(sizeof(User));
    if (new_user == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", new_user->username);

    printf("Enter password: ");
    scanf("%s", new_user->password);

    users[num_users++] = new_user;
    printf("User registered successfully.\n");
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i]->username, username) == 0 && strcmp(users[i]->password, password) == 0) {
            printf("Login successful.\n");
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

void add_customer() {
    if (num_customers == MAX_CUSTOMERS) {
        printf("Maximum number of customers reached.\n");
        return;
    }

    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    if (new_customer == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter customer name: ");
    scanf("%s", new_customer->name);

    printf("Enter customer balance: ");
    scanf("%lf", &new_customer->balance);

    customers[num_customers++] = new_customer;
    printf("Customer added successfully.\n");
}

int main() {
    int choice;
    int is_logged_in = 0;

    do {
        printf("\n1. Register\n2. Login\n3. Add Customer\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                is_logged_in = login();
                break;
            case 3:
                if (is_logged_in) {
                    add_customer();
                } else {
                    printf("You must be logged in to add customers.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    
    for (int i = 0; i < num_users; i++) {
        free(users[i]);
    }
    for (int i = 0; i < num_customers; i++) {
        free(customers[i]);
    }

    return 0;
}