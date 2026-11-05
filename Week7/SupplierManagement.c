
#include <stdio.h>
#include <string.h>

int main() {

    char name[100];
    char email[100];
    char phone[20];
    char town[50];
    char search[100];
    char choice[10];

    int supplierAdded = 0;

    do {

        printf("\n================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        fgets(choice, sizeof(choice), stdin);

        if (strcmp(choice, "1\n") == 0 ||
            strcmp(choice, "1") == 0) {

            printf("\nEnter supplier name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Enter email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';

            printf("Enter phone: ");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = '\0';

            printf("Enter town: ");
            fgets(town, sizeof(town), stdin);
            town[strcspn(town, "\n")] = '\0';

            supplierAdded = 1;

            printf("\nSupplier added successfully!\n");
        }

        else if (strcmp(choice, "2\n") == 0 ||
                 strcmp(choice, "2") == 0) {

            if (supplierAdded == 1) {

                printf("\n--- SUPPLIER DETAILS ---\n");
                printf("Name: %s\n", name);
                printf("Email: %s\n", email);
                printf("Phone: %s\n", phone);
                printf("Town: %s\n", town);

            } else {
                printf("\nNo supplier has been added yet.\n");
            }
        }

        else if (strcmp(choice, "3\n") == 0 ||
                 strcmp(choice, "3") == 0) {

            if (supplierAdded == 1) {

                printf("\nEnter supplier name to search: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';

                if (strcmp(search, name) == 0) {
                    printf("Supplier found!\n");
                } else {
                    printf("Supplier not found.\n");
                }

            } else {
                printf("\nPlease add a supplier first.\n");
            }
        }

        else if (strcmp(choice, "4\n") == 0 ||
                 strcmp(choice, "4") == 0) {

            if (supplierAdded == 1) {
                printf("\nSupplier name length: %zu\n",
                       strlen(name));
            } else {
                printf("\nPlease add a supplier first.\n");
            }
        }

        else if (strcmp(choice, "5\n") == 0 ||
                 strcmp(choice, "5") == 0) {

            printf("\nExiting Supplier Management System...\n");
        }

        else {
            printf("\nInvalid choice. Try again.\n");
        }

    } while (strcmp(choice, "5\n") != 0 &&
             strcmp(choice, "5") != 0);

    return 0;
}