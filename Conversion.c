#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 50


int selectBase() {
    int base;
    printf("\nChoose bases:");
    printf("\n2. Binary");
    printf("\n8. Octal");
    printf("\n10. Decimal");
    printf("\n16. Hexadecimal");

    while (1) {
        printf("\nEnter the base: ");
        scanf("%d", &base);
        if (base == 2 || base == 8 || base == 10 || base == 16) {
            return base;
        }
        printf("\nInvalid choice. Please choose a valid base.\n");
    }
}


int parseInputToDecimal(const char *input, int base) {
    int decimalValue = 0, multiplier = 1;
    int length = strlen(input);

    for (int i = length - 1; i >= 0; i--) {
        int digit;
        char c = input[i];

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else {
            printf("\nInvalid character in input for base %d.\n", base);
            return -1;
        }

        if (digit >= base) {
            printf("\nInvalid digit '%c' for base %d.\n", c, base);
            return -1;
        }

        decimalValue += digit * multiplier;
        multiplier *= base;
    }
    return decimalValue;
}


int getInput(int base) {
    char input[MAX_INPUT_LEN];
    int decimalValue;

    while (1) {
        printf("\nEnter value in base %d: ", base);
        scanf("%s", input);

        decimalValue = parseInputToDecimal(input, base);
        if (decimalValue != -1) {
            return decimalValue;
        }
    }
}

// Function to convert decimal to binary
void convertToBinary(int decimalValue) {
    char binary[MAX_INPUT_LEN] = {0};
    int index = 0;

    if (decimalValue == 0) {
        printf("\nIn Binary: 0\n");
        return;
    }

    while (decimalValue > 0) {
        binary[index++] = (decimalValue % 2) + '0';
        decimalValue /= 2;
    }

    printf("\nIn Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

// Function to convert decimal to octal
void convertToOctal(int decimalValue) {
    char octal[MAX_INPUT_LEN] = {0};
    int index = 0;

    if (decimalValue == 0) {
        printf("\nIn Octal: 0\n");
        return;
    }

    while (decimalValue > 0) {
        octal[index++] = (decimalValue % 8) + '0';
        decimalValue /= 8;
    }

    printf("\nIn Octal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", octal[i]);
    }
    printf("\n");
}

// Function to convert decimal to hexadecimal
void convertToHexadecimal(int decimalValue) {
    char hexadecimal[MAX_INPUT_LEN] = {0};
    int index = 0;

    if (decimalValue == 0) {
        printf("\nIn Hexadecimal: 0\n");
        return;
    }

    while (decimalValue > 0) {
        int remainder = decimalValue % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = remainder - 10 + 'A';
        }
        decimalValue /= 16;
    }

    printf("\nIn Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

// Function to display the converted value
void displayConvertedValue(int decimalValue, int targetBase) {
    switch (targetBase) {
        case 2:
            convertToBinary(decimalValue);
            break;
        case 8:
            convertToOctal(decimalValue);
            break;
        case 10:
            printf("\nIn Decimal: %d\n", decimalValue);
            break;
        case 16:
            convertToHexadecimal(decimalValue);
            break;
        default:
            printf("\nInvalid target base.\n");
    }
}

int main() {
    int inputBase, targetBase, decimalValue;

    printf("\nChoose the input base:");
    inputBase = selectBase();

    decimalValue = getInput(inputBase);

    printf("\nChoose the base for conversion:");
    targetBase = selectBase();

    displayConvertedValue(decimalValue, targetBase);

    return 0;
}
