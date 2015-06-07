//Name: Rodney Chen
//Date : 16/03/15
// Purpose: Tells you whether it is a leap year or not
//Test cases: 1581, 1800, 1900, 2000, 2004, 1950, 4000, 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0
#define START_GREG_CALENDAR 1582
int isLeapYear  (int year);
int year;
int main (int argc, char * argv[]){

	int intyear;
	printf("Enter the year you wish to check\n");
	scanf("%d" ,&intyear);
        int answer; 
	answer = isLeapYear(intyear);
	if (answer == TRUE){
	printf("%d is a leap year\n" ,intyear );
	} else {
	printf("%d is not a leap year\n" ,intyear);
	}
	return EXIT_SUCCESS;
}
        int isLeapYear (int year) {
	int leapyea;
	assert ( year >= START_GREG_CALENDAR);
 	if ((year % 400) == 0)
	leapyea = TRUE;
	else if (( year % 100) == 0)
	leapyea = FALSE;
	else if ((year % 4) == 0)
	leapyea = TRUE;
	else 
	leapyea = FALSE;

	if (year < START_GREG_CALENDAR){ 
	leapyea = FALSE;
        }
	return leapyea;
    }




