#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer {
    char name[50];
    char address[100];
    char phone[20];
};

int searchCustomerByName(const char *name, struct Customer *customer);
void storeCustomerName(const char *name);

#endif