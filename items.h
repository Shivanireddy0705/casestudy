#ifndef ITEMS_H
#define ITEMS_H

#define MAX_ITEMS 10
#define MAX_CART_ITEMS 20

struct Product {
    char name[50];
    float price;
    int quantity;
};

int readProductsFromFile(const char *filename, struct Product *products, int *numProducts);
void addToCart(const char *cartFilename, struct Product product);
void displayCart(const char *cartFilename);

#endif