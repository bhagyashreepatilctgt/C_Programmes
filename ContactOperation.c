#include <stdio.h>
#include <string.h>
#define MAX 100 
#define NAME_LEN 50 

typedef struct {
   char name[NAME_LEN];
   char number[15];
} Contact;
Contact contacts[MAX]; 
int count = 0;  

void addContact() {
   if (count < MAX) {
       printf("Enter Name: ");
       scanf("%s", contacts[count].name);
       printf("Enter Contact Number: ");
       scanf("%s", contacts[count].number);
      count++;
       printf("Contact added successfully!\n");
   } else {
       printf("Contact list is full!\n");
   }
}

void searchByName() {
   char searchName[NAME_LEN];
   printf("Enter the name to search: ");
   scanf("%s", searchName);
   int found = 0;
   for (int i = 0; i < count; i++) {
       if (strcmp(contacts[i].name, searchName) == 0) {
           printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].number);
           found = 1;
           break;
       }
   }
   if (!found) {
       printf("Contact not found!\n");
   }
}

void searchByNumber() {
   char searchNumber[15];
   printf("Enter the number to search: ");
   scanf("%s", searchNumber);
   int found = 0;
   for (int i = 0; i < count; i++) {
       if (strcmp(contacts[i].number, searchNumber) == 0) {
           printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].number);
           found = 1;
           break;
       }
   }
   if (!found) {
       printf("Contact not found!\n");
   }
}

void deleteContact() {
   char deleteName[NAME_LEN];
   printf("Enter the name of the contact to delete: ");
   scanf("%s", deleteName);
   int found = 0;
   for (int i = 0; i < count; i++) {
       if (strcmp(contacts[i].name, deleteName) == 0) {
       
           for (int j = i; j < count - 1; j++) {
               contacts[j] = contacts[j + 1];
           }
           count--;
           printf("Contact deleted successfully!\n");
           found = 1;
           break;
       }
   }
   if (!found) {
       printf("Contact not found!\n");
   }
}

void updateContact() {
   char updateName[NAME_LEN];
   printf("Enter the name of the contact to update: ");
   scanf("%s", updateName);
   int found = 0;
   for (int i = 0; i < count; i++) {
       if (strcmp(contacts[i].name, updateName) == 0) {
           printf("Enter new contact number: ");
           scanf("%s", contacts[i].number);
           printf("Contact updated successfully!\n");
           found = 1;
           break;
       }
   }
   if (!found) {
       printf("Contact not found!\n");
   }
}

void displayMenu() {
   printf("1. Add Contact\n");
   printf("2. Search by Name\n");
   printf("3. Search by Number\n");
   printf("4. Delete Contact\n");
   printf("5. Update Contact\n");
   printf("6. Exit\n");
   printf("Enter your choice: ");
}
int main() {
   int choice;
   do {
       displayMenu();
       scanf("%d", &choice);
       switch (choice) {
           case 1:
               addContact();
               break;
           case 2:
               searchByName();
               break;
           case 3:
               searchByNumber();
               break;
           case 4:
               deleteContact();
               break;
           case 5:
               updateContact();
               break;
           case 6:
               printf("Exiting...\n");
               break;
           default:
               printf("Invalid choice! Please try again.\n");
       }
   } while (choice != 6);
   return 0;
}        