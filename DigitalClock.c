/*
    Program to Print a Digital Clock showing time (both in 24-hour format and 12-hour format)
     in IST, UTC and GMT
*/

#include <stdio.h>
#include <time.h>

// print time on console in diffrent time zone
void printTime(struct tm *local_time, const char *zone)
{
    char time[80];
    //strftime() is a function in C which is used to format date and time
    strftime(time, sizeof(time), "%Y-%m-%d %H:%M:%S", local_time);
    printf("%s: %s\n", zone, time);
}

void delay(int sec)
{
    sleep(sec);
}

int main()
{

    time_t current_time;
    struct tm *local_time;
    struct tm *utc_time;

    // loop to diaplay the whole clock and refresh it in every 1 sec
    for (int i = 0; i < 500; i++)
    {
        system("cls");
        time(&current_time);

        local_time = localtime(&current_time);

        utc_time = gmtime(&current_time);

        printf("i: %d\n", i);
        printf("Current Time in IST:\n");
        printTime(local_time, "IST");

        printf("\nCurrent Time in UTC:\n");
        printTime(utc_time, "UTC");

        printf("\nCurrent Time in GMT:\n");
        printTime(utc_time, "GMT");

        delay(1);
    }

    return 0;
}