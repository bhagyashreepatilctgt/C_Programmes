#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_IP_LEN 15 // Max length of an IPv4 address string

int isValidLength(const char *ip) {
    if (strlen(ip) > MAX_IP_LEN) {
        printf("\nInvalid: IP address ");
        return 0;
    }
    return 1;
}

int containsOnlyDigitsAndDots(const char *ip) {
    int dotCount = 0;
    for (int i = 0; ip[i] != '\0'; i++) {
        if (isdigit(ip[i])) continue;
        if (ip[i] == '.') {
            dotCount++;
        } else {
            return 0;
        }
    }
    return (dotCount == 3); 
}

void removeSeg(const char *ip, char seg[4][4]) {
    char temp[16];
    strcpy(temp, ip);

    char *token = strtok(temp, ".");
    int index = 0;
    while (token != NULL && index < 4) {
        strcpy(seg[index++], token);
        token = strtok(NULL, ".");
    }
}

int areSegmentsInRange(char seg[4][4]) {
    for (int i = 0; i < 4; i++) {
        int num = atoi(seg[i]);
        if (num < 0 || num > 255) return 0;
    }
    return 1;
}

int isValidIPv4(const char *ip) {
    if (!isValidLength(ip)) return 0;
    if (!containsOnlyDigitsAndDots(ip)) return 0;

    char segments[4][4];
    removeSeg(ip, segments);

    return areSegmentsInRange(segments);
}

int main() {
    char ip[16];
    printf("Enter an IPv4 address: ");
    scanf("%15s", ip); // Avoids buffer overflow

    printf("\nProvided IP address: %s", ip);

    if (isValidIPv4(ip))
        printf("\nThe IP address is valid.\n");
    else
        printf("\nThe IP address is invalid.\n");

    return 0;
}
