#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    char input[100];
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            continue;
        }

        if (sscanf(input, "%d", &value) == 1)
        {
            return value;
        }

        printf("Invalid input. Enter a whole number.\n");
    }
}

float readFloat(const char *prompt)
{
    char input[100];
    float value;
    char extra;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            continue;
        }

        if (sscanf(input, " %f %c", &value, &extra) == 1)
        {
            return value;
        }

        printf("Invalid input. Enter a number.\n");
    }
}

void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}