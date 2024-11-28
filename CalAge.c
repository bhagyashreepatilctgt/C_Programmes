 //Program to Find current age of a person given date of birth of the person
#include <stdio.h>
#include <time.h>

int main() {
    int bd, bm,by;
    int cd, cm, cy;
    int age;

    // Get current date
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    cd = tm->tm_mday;
    cm = tm->tm_mon + 1; 
     cy = tm->tm_year + 1900; 

    // Get date of birth from user
    printf("Enter your date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &bd, &bm, &by);

    
    age = cy -by;

    // Adjust age if the bd has not occurred yet this year
    if (cm < bm || (cm == bm && cd < bd)) {
        age--;
    }

    
    printf("Your current age is: %d years\n", age);

    return 0;
}