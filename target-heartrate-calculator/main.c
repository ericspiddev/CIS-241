/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: user's birthday, current date
 * Outputs: user's age, user's max heart rate, user's target heart range
 * Description: This program asks the user for their birthday and then the current date. It then calculates the
 * user's age, max heart rate, and target heart range. These calculations are based on a method given by the
 * American Heart Association (this is not professional medical advice at all please consult a doctor for that)
 ***/
#include <stdio.h>
#include <string.h> // libs needed for program
#include <stdlib.h>

#define SIZE 12 // macro defining how big the size should be for a string
#define MAX_DATA_SIZE 5 // max size of the date data string

// struct to hold date data for both user's birthday and the current date
struct Date {
    int day;
    int month;
    int year;
};

//struct to hold data for a user in particular everything that is needed to be shown to the user at the end of calculations
struct Person {
    int age;
    int maxHeartRate;
    double targetHeartRangeMax;
    double targetHeartRangeMin;
};

// enum for switch case when assigning dates
enum DateData {
    MONTH,
    DAY,
    YEAR
};

/*** Function Prototypes ***/
void promptUser(char user [],char current[]);
void parseDate(char dateString[], struct Date* date);
void assignDates(int data, enum DateData partOfDate, struct Date* date);
int decideUserAge(int uday, int umonth, int uyear, int cday, int cmonth, int cyear);
void calculateStats(struct Person *person);
void printResults(int age, int maxHeartRate, double targetHeartRangeMin, double targetHeartRangeMax);

/**
 * @brief The main function of the program this executes and calls all other functions
 *
 * @return int returns a zero if the program terminated successfully
 */
int main(){

    struct Person user;
    struct Date userBirthday;
    struct Date currentDate = {.day = 0, .month = 0, .year = 0};
    char userBirthdayString[SIZE];
    char currentDateString[SIZE];

    printf("-------------~Target Heart Rate Calculator~-------------\n");
    promptUser(userBirthdayString, currentDateString);
    parseDate(currentDateString, &currentDate);
    parseDate(userBirthdayString, &userBirthday);
    user.age = decideUserAge(userBirthday.day, userBirthday.month, userBirthday.year, currentDate.day, currentDate.month, currentDate.year);
    calculateStats(&user);
    printResults(user.age, user.maxHeartRate, user.targetHeartRangeMin, user.targetHeartRangeMax);
    return 0;
}

/**
 * @brief This functions purpose is to prompt the user to enter both their birthday and the current day
 *
 * @param user - the string meant to hold the user's bday
 * @param current - the string meant to hold the current date
 */
void promptUser(char user[] , char current[]){
    printf("Enter your birthday in the format MM/DD/YYYY: ");
    scanf("%s", user);
    printf("Enter today's current date in the format MM/DD/YYYY: ");
    scanf("%s", current);
}

/**
 * @brief This function parses the date passed in and then assigns to a Date struct the
 * parsed day, month, and year
 * @param dateString - the string of chars to be parsed
 * @param date - the struct to assign the data to
 */
void parseDate(char dateString[], struct Date* date){
    char holdDate[MAX_DATA_SIZE] = "";
    int holdDateIndex = 0;
    enum DateData partOfDate = MONTH;
     for(int i=0; i <= strlen(dateString); i++){
        if(dateString[i] == '/' || i == (strlen(dateString))){
            assignDates(atoi(holdDate), partOfDate, date);
            partOfDate++;
            holdDateIndex = 0;
            strcpy(holdDate, "");
        }
        else{
            holdDate[holdDateIndex++] = dateString[i];
        }
     }
}

/**
 * @brief This function assigns a value to either the day, month or year field of
 * a date struct it decides based on an enum passed into the function
* @param data - the value to be assigned
 * @param partOfDate - the enum that specifies which field should be assigned the data value
 * @param date - a date struct that has its fields assigned
 */
void assignDates(int data, enum DateData partOfDate, struct Date* date){
    switch(partOfDate){
        case DAY:
            date->day = data;
            break;
        case MONTH:
            date->month = data;
            break;
        case YEAR:
            date->year = data;
            break;
        default:
            break;
    }
}

/**
 * @brief This function calculates the user's age based on the user's birthday and the current date
 *
 * @param uday - the day of the user's birthday
 * @param umonth - the month of the user's birthday
 * @param uyear - the year of the user's birthday
 * @param cday - the current day
 * @param cmonth - the current month
 * @param cyear - the current year
 * @return int the user's age based on all of the parameters specifed aboves
 */
int decideUserAge(int uday, int umonth, int uyear, int cday, int cmonth, int cyear){
    if(umonth < cmonth){
        return cyear - uyear;
    }
    else if(umonth > cmonth){
        return cyear-uyear -1;
    }
    else{
        if(cday > uday)
            return cyear - uyear - 1;
        else{
            if(cday == uday)
                printf("Happy birthday!\n");
            return cyear - uyear;
        }
    }
}

/**
 * @brief This function calculates the max heart rate and target heart rate range as specifed by the
 * AHA referenced in the homework doc
 * @param user - the user struct to be modifed with calculations
 */
void calculateStats(struct Person *user){
    user->maxHeartRate = 220 - user->age;
    user->targetHeartRangeMin = user->maxHeartRate * 0.5;
    user->targetHeartRangeMax = user->maxHeartRate * 0.8;
}

/**
 * @brief This function is responsible for printing the results to the user after all the proper calculations
 * have been done.
 * @param age - the user's age that will be printed
 * @param maxHeartRate - the max heart rate allowed for the user based on age
 * @param targetHeartRangeMin - the lower bound of the user's target heart rate range
 * @param targetHeartRangeMax - the upper bound of the user's target heart rate range
 */
void printResults(int age, int maxHeartRate, double targetHeartRangeMin, double targetHeartRangeMax)
{
    printf("User's Age: \t%i year(s)\n", age);
    printf("User's Max Heart Rate: \t%i bpm\n", maxHeartRate);
    printf("User's Target Heart Range %0.2lf-%0.2lf bpm\n", targetHeartRangeMin, targetHeartRangeMax);
}
