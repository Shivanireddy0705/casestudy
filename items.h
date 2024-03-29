#ifndef ITEMS_H
#define ITEMS_H

#define MAX_ITEMS 10

// Structure to represent a product
struct Product {
    char name[50];
    float price;
    int quantity;
};

// Array of products
struct Product products[MAX_ITEMS] = {
    {"Apple", 30.0, 10},
    {"Banana", 15.0, 20},
    {"Orange", 45.0, 15},
    {"Mango", 60.0, 8},
    {"Grapes", 80.0, 5},
    {"Pineapple", 100.0, 3},
    {"Strawberry", 120.0, 10},
    {"Blueberry", 150.0, 7},
    {"Kiwi", 90.0, 12},
    {"Coconut", 35.0, 20}
};

#endif