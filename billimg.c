#include <stdio.h>

#define MAX_ITEMS 100  // Maximum number of items in the bill

struct Item {
    char name[50];
    double price;
    int quantity;
};

int main() {
    struct Item items[MAX_ITEMS];
    int num_items;
    double total = 0.0;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &num_items);

    // Input items details
    for (int i = 0; i < num_items; i++) {
        printf("Item %d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", items[i].name);  // Read item name with spaces
        printf("Price: ");
        scanf("%lf", &items[i].price);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        total += items[i].price * items[i].quantity;
    }

    // Generate bill
    printf("\n===== BILL =====\n");
    printf("Item Name\tPrice\tQuantity\tTotal\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%.2lf\t%d\t\t%.2lf\n", items[i].name, items[i].price, items[i].quantity,
               items[i].price * items[i].quantity);
    }
    printf("\nTotal: %.2lf\n", total);

    return 0;
}
