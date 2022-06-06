/**
 * Author: Eric Spidle
 * Class: CIS 241-01
 * Instructor: Professor Bhuse
 * Input: A string with day of the week, month, day of the month,
 * Output: The smallest integer that was put in
 * Description: The user inputs 20 integer values and those value are stored in an array
 *  than the smallest of those is printed to the screen
 */
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 50

void promptUser();
void getString(char []);
void printData(char str[]);

/**
 * @brief - the entry point of the program that calls all functions
 * and directs the flow of the program
 * @return int returns a 0 to indicate program conclusion
 */
int main(void)
{
    char str[STRING_SIZE] = { 0 };
    promptUser();
    getString(str);
    printData(str);
    return 0;
}

/**
 * @brief - Prompts the user to enter a string in the certain format so the data can be parsed
 */
void promptUser()
{
    printf("Enter a date and time in the following format: day of the week,month,date,year,hours,minutes,seconds\n");
    printf("Use military time and write out the month and day of the week Example(Saturday, July 8, 2017, 22:14:10)\n");
}

/**
 * @brief takes in the user string
 *
 * @param str - the array of characters that will hold the user's string
 */
void getString(char str[])
{
    int index =0;
    char character;
    while(index < STRING_SIZE && (character = getchar()) !='\n')
    {
        str[index++] = character;
    }
}

/**
 * @brief - function used to print the data that was input by the user
 * utilzies strtok to seperate the strings
 *
 * @param str - string to be parsed
 */
void printData(char str[])
{
    char* token = NULL;
    token = strtok(str, ", :");
    int pass = 0;
    while(token != NULL)
    {
        switch(pass)
        {
            case 0: // skip day of the week
                break;
            case 1:
                 printf("Month:%s\n", token);
                break;
            case 2:
                 printf("Day:%s\n", token);
                break;
            case 3:
                 printf("Year:%s\n", token);
                break;
            case 4:
                 printf("Hour:%s\n", token);
                break;
            case 5:
                 printf("Minute:%s\n", token);
                break;
            case 6:
                printf("Second:%s\n", token);
                break;
            default:
                break;
        }
        token = strtok(NULL, ",: ");
        ++pass;
    }
}