#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
 
int main (int argc, char *argv[]) {


assert (dayOfWeek (MONDAY, TRUE, 1, 27) == WEDNESDAY);
assert (dayOfWeek (MONDAY, TRUE, 4, 8) == FRIDAY);
assert (dayOfWeek (MONDAY, TRUE, 4, 26) == TUESDAY);
assert (dayOfWeek (MONDAY, TRUE, 7, 1) == FRIDAY);
assert (dayOfWeek (MONDAY, TRUE, 7, 18) == MONDAY);
assert (dayOfWeek (MONDAY, TRUE, 10, 10) == MONDAY);
assert (dayOfWeek (MONDAY, TRUE, 12, 20) == TUESDAY);
assert (dayOfWeek (MONDAY, TRUE, 1, 1) == FRIDAY);
assert (dayOfWeek (MONDAY, TRUE, 1, 26) == TUESDAY);
assert (dayOfWeek (MONDAY, TRUE, 3, 26) == SATURDAY);
assert (dayOfWeek (MONDAY, TRUE, 3, 27) == SUNDAY);
assert (dayOfWeek (MONDAY, TRUE, 4, 25) == MONDAY);
   assert (dayOfWeek (MONDAY, FALSE, 4, 4) == MONDAY);
assert (dayOfWeek (TUESDAY, FALSE, 4, 4) == TUESDAY);
assert (dayOfWeek (WEDNESDAY, FALSE, 4, 4) == WEDNESDAY);
assert (dayOfWeek (THURSDAY, FALSE, 4, 4) == THURSDAY);
assert (dayOfWeek (FRIDAY, FALSE, 4, 4) == FRIDAY);
assert (dayOfWeek (SATURDAY, FALSE, 4, 4) == SATURDAY);
assert (dayOfWeek (SUNDAY, FALSE, 4, 4) == SUNDAY);

  assert(dayOfWeek (THURSDAY, TRUE ,10,29) == TUESDAY);
  assert(dayOfWeek (MONDAY, FALSE,11,17) == THURSDAY);
  assert(dayOfWeek (FRIDAY, TRUE , 1, 2) == WEDNESDAY);  
  assert(dayOfWeek (THURSDAY, TRUE ,12,22) == SUNDAY);
  assert(dayOfWeek (MONDAY, TRUE ,10,31) == MONDAY);


   assert (dayOfWeek (MONDAY, TRUE, 4, 4) == MONDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 4, 4) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 4, 4) == WEDNESDAY);  
   assert (dayOfWeek (THURSDAY, TRUE, 4, 4) == THURSDAY);
   assert (dayOfWeek (FRIDAY, TRUE, 4, 4) == FRIDAY);
   assert (dayOfWeek (SATURDAY, TRUE, 4, 4) == SATURDAY);
   assert (dayOfWeek (SUNDAY, TRUE, 4, 4) == SUNDAY);
   assert (dayOfWeek ( MONDAY, TRUE, 4, 6) == WEDNESDAY);

   assert (dayOfWeek ( MONDAY, TRUE, 6, 9) == THURSDAY);

   assert (dayOfWeek ( MONDAY, TRUE, 8, 13) == SATURDAY);

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
 
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
 
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
 
   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int doomsdaymonth;
        if (month == 3) {
          doomsdaymonth = 14;
        }
        if (month == 2){
          if (leapYear ){ 
          doomsdaymonth = 29;
         }  else {
           doomsdaymonth = 28;
         }
        }
        if (month == 1){
          if (leapYear) {
            doomsdaymonth = 4;
         } else {
            doomsdaymonth = 3;
         }
	}
        if (month == 4) {
          doomsdaymonth = 4;
        }
        if (month == 5) {
           doomsdaymonth = 9;
        }
        if (month == 6) {
           doomsdaymonth = 6;
        }
        if (month == 7) {
            doomsdaymonth = 11;
        }
        if (month == 8) {
            doomsdaymonth = 8;
        }
        if (month == 9) {
            doomsdaymonth = 5;
        }
        if (month == 10) {
            doomsdaymonth = 10;
        }
        if (month == 11) {
            doomsdaymonth = 7;
        }
        if (month == 12) {
             doomsdaymonth = 12;
        }
      int offsetinDayweek = (day - doomsdaymonth)%7;
      int answer = (doomsday + offsetinDayweek)%7;
         if (answer < 0) {
            answer +=7;
            answer = answer%7;
        } 
         else if (answer > 0) { 
             answer = answer%7;
        } 
      return (answer);

       }  
