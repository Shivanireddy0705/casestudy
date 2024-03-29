#ifndef CUSTOMER_H
#define CUSTOMER_H

// Structure to represent a customer
struct Customer {
    char name[50];
    char address[100];
    char phone[20];
};
struct Customer customer = {
    "XYZ",
    "PES UNIVERSITY ELECTRONIC CITY",
    "560100"
};

extern struct Customer customer;

#endif