#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "items.h"

int readProductsFromFile(const char *filename, struct Product *products, int *numProducts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    int index = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL && index < MAX_ITEMS) {
        char name[50];
        char priceStr[20];
        char quantityStr[20];
        sscanf(line, "%[^,],%[^,],%s", name, priceStr, quantityStr);

        strcpy(products[index].name, name);
        products[index].price = atof(priceStr);
        products[index].quantity = atoi(quantityStr);
        index++;
    }

    *numProducts = index;
    fclose(file);
    return 1;
}

void addToCart(const char *cartFilename, struct Product product) {
    FILE *file = fopen(cartFilename, "a");
    if (file == NULL) {
        return;
    }

    fprintf(file, "%s,%.2f,%d\n", product.name, product.price, product.quantity);
    fclose(file);
}

void displayCart(const char *cartFilename) {
    FILE *file = fopen(cartFilename, "r");
    if (file == NULL) {
        printf("Cart is empty.\n");
        return;
    }

    printf("Cart Contents:\n");
    char line[100];
    float totalCost = 0.0f;
    while (fgets(line, sizeof(line), file) != NULL) {
        char name[50];
        float price;
        int quantity;
        sscanf(line, "%[^,],%f,%d", name, &price, &quantity);

        printf("%s (Rs. %.2f, %d)\n", name, price, quantity);
        totalCost += price * quantity;
    }

    printf("Total Cost: Rs. %.2f\n", totalCost);
    fclose(file);
}