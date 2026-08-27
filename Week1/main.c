#include <stdio.h>

int main() {
    char municipalityName[100];
    char mayorName[100];
    int population;

    // Display system title
    printf("=============================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=============================================\n\n");

    // Welcome message
    printf("Welcome to Windhoek Municipality\n\n");

    // Get Municipality Name
    printf("Enter Municipality Name: ");
    fgets(municipalityName, sizeof(municipalityName), stdin);

    // Get Mayor's Name
    printf("Enter Mayor's Name: ");
    fgets(mayorName, sizeof(mayorName), stdin);

    // Get Population
    printf("Enter Population: ");
    scanf("%d", &population);

    // Display report
    printf("\n=============================================\n");
    printf("        MUNICIPAL INFORMATION REPORT\n");
    printf("=============================================\n");

    printf("Municipality Name : %s", municipalityName);
    printf("Mayor's Name      : %s", mayorName);
    printf("Population        : %d\n", population);

    printf("=============================================\n");

    return 0;
}