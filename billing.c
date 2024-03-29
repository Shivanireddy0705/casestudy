#include <stdio.h>
#include "items.h" // Include the items.h header file
#include "customer.h"

int main() {
    float totalBill = 0.0;
    int totalItems = 0;

    // Print customer details
    printf("Customer Name: %s\n", customer.name);
    printf("Customer Address: %s\n", customer.address);
    printf("Customer Phone: %s\n\n", customer.phone);

    // Calculate the total bill and total items
    for (int i = 0; i < MAX_ITEMS; i++) {
        float productTotal = products[i].price * products[i].quantity;
        totalBill += productTotal;
        totalItems += products[i].quantity;
        printf("Product: %s\nPrice: Rs. %.2f\nQuantity: %d\nTotal: Rs. %.2f\n\n",
               products[i].name, products[i].price, products[i].quantity, productTotal);
    }

    printf("Total Number of Items: %d\n", totalItems);
    printf("Total Bill: Rs. %.2f\n", totalBill);

    return 0;
}