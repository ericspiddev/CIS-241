/***
 * Name: Eric Spidle
 * Course: CIS-241
 * Instructor: Professor Bhuse
 * Input/Output:
 * Description:
 ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 12
#define MAX_DATA_SIZE 5

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
    DAY,
    MONTH,
    YEAR
};

void promptUser(char user [],char current[]);
void parseDate(char dateString[], struct Date* date);
void assignDates(int data, enum DateData partOfDate, struct Date* date);
int decideUserAge(int uday, int umonth, int uyear, int cday, int cmonth, int cyear);
void calculateStats(struct Person *person);
void printResults(int age, int maxHeartRate, double targetHeartRangeMin, double targetHeartRangeMax);
/**
 * @brief
 *
 * @return int
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
 * @brief
 *
 * @param user
 * @param current
 */
void promptUser(char user[] , char current[]){
    printf("Enter your birthday in the format MM/DD/YYYY: ");
    scanf("%s", user);
    printf("Enter today's current date in the format MM/DD/YYYY: ");
    scanf("%s", current);
}

/**
 * @brief
 *
 * @param dateString
 * @param date
 */
void parseDate(char dateString[], struct Date* date){
    char holdDate[MAX_DATA_SIZE] = "";
    int holdDateIndex = 0;
    enum DateData partOfDate = DAY;
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
 * @brief
 *
 * @param data
 * @param partOfDate
 * @param date
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
 * @brief
 *
 * @param uday
 * @param umonth
 * @param uyear
 * @param cday
 * @param cmonth
 * @param cyear
 * @return int
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
 * @brief
 *
 * @param user
 */
void calculateStats(struct Person *user){
    user->maxHeartRate = 220 - user->age;
    user->targetHeartRangeMin = user->maxHeartRate * 0.5;
    user->targetHeartRangeMax = user->maxHeartRate * 0.8;
}

/**
 * @brief
 *
 * @param age
 * @param maxHeartRate
 * @param targetHeartRangeMin
 * @param targetHeartRangeMax
 */
void printResults(int age, int maxHeartRate, double targetHeartRangeMin, double targetHeartRangeMax)
{
    printf("User's Age: \t%i year(s)\n", age);
    printf("User's Max Heart Rate: \t%i bpm\n", maxHeartRate);
    printf("User's Target Heart Range %0.2lf-%0.2lf bpm\n", targetHeartRangeMin, targetHeartRangeMax);
}
