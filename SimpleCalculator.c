// Simple Calculator
#include <stdio.h>
#include <stdbool.h>


int calSum(int no1, int no2)
{ // Functions to print Addition
    return no1 + no2;
}
int calSub(int no1, int no2)
{ // Functions to print Subtractoion
    return no1 - no2;
}
int calMul(int no1, int no2)
{ // Functions to print Multiplication
    return no1 * no2;
}
int calDiv(int no1, int no2)
{ // Functions to print Division
    return no1 / no2;
}
int main()
{
    int choice;
    int no1, no2;
    printf("Enter The Numbers\n");
    scanf("%d%d", &no1, &no2);
    int result;
    do
    {
        printf("Addition\n");
        printf("Subtraction\n");
        printf("Multiplication\n");
        printf("Division\n");
        printf("Enter Your Choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            result = calSum(no1, no2);
            printf("Addition is %d\t\n", result);
            break;
        case 2:
            result = calSub(no1, no2);
            printf("Subtraction is %d\t\n", result);
            break;
        case 3:
            result = calMul(no1, no2);
            printf("Multiplication is %d\t\n", result);
            break;
        case 4:
            result = calDiv(no1, no2);
            printf("Division is %d\t\n", result);
            break;
        default:
            printf("Invalid Operation\t");
        }
    } while (true);
}