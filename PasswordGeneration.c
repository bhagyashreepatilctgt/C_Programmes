#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MINLENGTH 8
#define SUGGESTIONS 3


bool checkLength(char pass[]) {
    return strlen(pass) >= MINLENGTH;
}


bool checkUpperCase(char pass[]) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') {
            return true;
        }
    }
    return false;
}


bool checkLowerCase(char pass[]) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] >= 'a' && pass[i] <= 'z') {
            return true;
        }
    }
    return false;
}


bool checkDigit(char pass[]) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] >= '0' && pass[i] <= '9') {
            return true;
        }
    }
    return false;
}


bool checkSpecialCharacter(char pass[]) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if ((pass[i] >= 32 && pass[i] <= 47) || 
            (pass[i] >= 58 && pass[i] <= 64) || 
            (pass[i] >= 91 && pass[i] <= 96) || 
            (pass[i] >= 123 && pass[i] <= 126)) {
            return true;
        }
    }
    return false;
}


bool isStrongPassword(char pass[]) {
    return checkLength(pass) && checkUpperCase(pass) && 
           checkLowerCase(pass) && checkDigit(pass) && 
           checkSpecialCharacter(pass);
}


void generateStrongPasswords(char suggestions[][20]) {
    const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "abcdefghijklmnopqrstuvwxyz"
                          "0123456789"
                          "!@#$%^&*()_+[]{}|;:,.<>?";
   

    for (int i = 0; i < SUGGESTIONS; i++) {
        for (int j = 0; j < MINLENGTH; j++) {
            suggestions[i][j] = charset[rand() % strlen(charset)];
        }
        suggestions[i][MINLENGTH] = '\0'; 
    }
}


int main() {
    char pass[20];
    char suggestions[SUGGESTIONS][20];

    printf("Enter Password: ");
    scanf("%s", pass);

    if (isStrongPassword(pass)) {
        printf("Valid Password\n");
    } else {
        printf("Weak Password\n");
        printf("Suggested Strong Passwords:\n");
        generateStrongPasswords(suggestions);
        for (int i = 0; i < SUGGESTIONS; i++) {
            printf("%s\n", suggestions[i]);
        }
    }

    return 0;
}
