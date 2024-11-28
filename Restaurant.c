#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dish {
    char name[20];
    int price;
};

struct Dish *menuItems;

void showMenu(int itemCount) {
    printf("\nAvailable Dishes:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s\t%d\n", menuItems[i].name, menuItems[i].price);
    }
}

float TotalAmount(int itemCount, float gstPercentage, float serviceTaxPercentage) {
    char selectedDish[20];
    int quantity;
    float totalAmount = 0;
    int dishCount;

    printf("How many dishes would you like to order? ");
    scanf("%d", &dishCount);

    for (int i = 0; i < dishCount; i++) {
        printf("Enter the name of the dish you want to order: ");
        scanf("%s", selectedDish);

        int found = 0;
        for (int j = 0; j < itemCount; j++) {
            if (strcmp(menuItems[j].name, selectedDish) == 0) {
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                totalAmount += menuItems[j].price * quantity;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Dish not found: %s\n", selectedDish);
        }
    }

    float gst = totalAmount * gstPercentage / 100;
    float serviceTax = totalAmount * serviceTaxPercentage / 100;
    float finalAmount = totalAmount + gst + serviceTax;

    printf("\nTotal Amount: %.2f\n", totalAmount);
    printf("GST (%.2f%%): %.2f\n", gstPercentage, gst);
    printf("Service Tax (%.2f%%): %.2f\n", serviceTaxPercentage, serviceTax);
    printf("Final Amount: %.2f\n", finalAmount);

    return finalAmount;
}

int main() {
    int itemCount;
    printf("Enter the number of dishes: ");
    scanf("%d", &itemCount);

    menuItems = (struct Dish *)malloc(itemCount * sizeof(struct Dish));
    if (menuItems == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter Dish Name and Price (format: name price):\n");
    for (int i = 0; i < itemCount; i++) {
        scanf("%s %d", menuItems[i].name, &menuItems[i].price);
    }

    float gstPercentage = 5.0;
    float serviceTaxPercentage = 10.0;

    int option;
    do {
        printf("\n1 - View Menu\n");
        printf("2 - Order Dishes and Calculate Total Amount\n");
        printf("3 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                showMenu(itemCount);
                break;
            case 2:
                TotalAmount(itemCount, gstPercentage, serviceTaxPercentage);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 3);

    free(menuItems);
    return 0;
}
