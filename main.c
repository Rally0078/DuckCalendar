#include "calendar.h"

int main(int argc, char* argv[])
{
  char current_date_time[38];
  
  int status = get_time_str(current_date_time, argc, argv);
  if (status)
  {
    fprintf(stderr, "\nError getting local time and date! Exiting...\n");
    return -1;
  }
  printf("\n");
  printf("Local time and date is %s", current_date_time);
  status = print_calendar();
  if (status)
  {
    printf("\nError creating calendar! Exiting...\n");
    return -1;
  }
  return 0;
}
