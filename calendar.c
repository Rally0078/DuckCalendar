#include "calendar.h"

char *days[] = {"Sun", "Mon", "Tue", "Wed","Thu","Fri","Sat"};
char *months[] = {"January", "February","March","April","May","June","July","August","September","October","November","December"};

int get_time_str(char *time_str)
{
    time_t time_raw;
    time(&time_raw);
    struct tm *local_time;
    local_time = localtime(&time_raw);
    strcpy(time_str, asctime(local_time));
    if (!local_time || !time_str || !strlen(asctime(local_time)))
        return -1;
    return 0;
}

int print_calendar()
{
    time_t time_now;
    time(&time_now);
    struct tm *local_now;
    local_now = localtime(&time_now);

    int mod_current_date = (local_now->tm_mday - 1) % 7;
    int day_of_start = local_now->tm_wday - mod_current_date;
	if(day_of_start<0)
		day_of_start = day_of_start+7;		//if day_of_start is negative, do magic modular arithmetic
    int crossed_flag = 0;

	int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int no_of_days;
    if(local_now->tm_mon == 1)
    {
            if((local_now->tm_year+1900)%400==0)
                no_of_days = month_days[local_now->tm_mon]+1;
            else if((local_now->tm_year+1900)%100 == 0)
                no_of_days = month_days[local_now->tm_mon];
            else if((local_now->tm_year+1900)%4 == 0)
                no_of_days = month_days[local_now->tm_mon]+1;
    }
    no_of_days = no_of_days = month_days[local_now->tm_mon];
    printf("\n");
    printf("%19s %d\n", months[local_now->tm_mon], local_now->tm_year + 1900);
    for (int i = 0; i < 39; i++)
        printf("=");
    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
            printf("   %s", days[i]);
        else
            printf("  %s", days[i]);
    }
    printf("\n");
	//Print the calendar itself with spaces infront of the first date of the month
    for (int i = 0; i < day_of_start; i++)
        printf("%5s", "");
    for (int i = 1; i <= no_of_days; i++)
    {

        if (i == local_now->tm_mday)
        {
            if(i<=9)
                printf("  | %d|", i);
            else           	
                printf("  |%d|", i);
			crossed_flag = 1;
        }
        else if (crossed_flag == 1)
        {
            if(day_of_start == 0)
                printf("%5d",i);
            else
                printf("%4d", i);
            crossed_flag = 0;
        }
        else
        {
                printf("%5d", i);
        }

        day_of_start = (day_of_start + 1) % 7;

        if (day_of_start == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    for (int i = 0; i < 39; i++)
        printf("=");
    printf("\n\n");
    return 0;
}
