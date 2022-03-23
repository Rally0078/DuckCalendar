#include "calendar.h"

int main(int argc, char* argv[])
{
  char current_date_time[30];
  
  int status = get_time_str(current_date_time);
  if (status == -1)
  {
    printf("\nError getting local time and date! Exiting...\n");
    return -1;
  }
  printf("Local time and date is %s", current_date_time);
  status = print_calendar();
  if (status)
  {
    printf("\nError creating calendar! Exiting...\n");
    return -1;
  }
  return 0;
}
