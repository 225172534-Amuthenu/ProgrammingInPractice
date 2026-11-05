#include<stdio.h>
int main() {
    char supplierName[50];
    float price;
    float budget;
    int registered;
    int documentsComplete;

    printf("Enter suplier name: ");
    scanf("%49s", supplierName);

    printf("Enter tender price: ");
    scanf("%f",&price);

    printf("Enter budget: ");
    scanf("%f", &budget);

    printf("Is registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);

    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documentsComplete);

    if (registered == 0 || documentsComplete == 0)
     {
       printf("\nSupplier: %s\n", supplierName);
       printf("status: Disqualified\n");
     }
     else
     {
        printf("\nSupplier: %s\n", supplierName);
        printf("status: Qualified\n");
     }     
     
     return 0;
}