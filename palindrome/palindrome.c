/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: A string
 * Outputs: Wether or not the input string is a palindrome
 * Description: This program allows the user to input a string and it then uses recursion
 * to check if the string is a palindrome
 ***/
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // libs needed for the program
#include <ctype.h>

#define MAX_SIZE 50 // max size of array

void programStart();
int testPalindrome(char string[]); // function prototypes
void getUserString(char str[]);
void results(char str[]);
 
/**
 * @brief -The main execution and entry point of the program that calls all the functions
 *
 * @return int - return 0 when it is done executing
 */
int main()
{
    char userString[MAX_SIZE] = ""; // init string
    programStart();
    getUserString(userString);
    printf("%s ", userString);
    if (testPalindrome(userString) == 1 )
    {
        printf("is a palindrome\n");
    }
    else
        printf("is not a palindrome\n");
    return 0;
}

/**
 * @brief Prompts to kick the program off
 *
 */
void programStart()
{
    printf("-----------~~~Palindrome Checker~~~-----------\n");
    printf("Enter a string to test if it is a palindrome(50 char max)\n"); // prompts
    printf("Space and punctuation will be ignored ");
}
/**
 * @brief this recursive function calls itself to check and see if the passed in string by the user
 * is a palindrome or not
 *
 * @param string - the string to bes tested
 * @return int - a 1 if the string is a palindrome a 0 if it is not
 */
int testPalindrome(char string[])
{
    int l = strlen(string);
    if(l == 1)
        return 1;
    else if(string[0] == string[l - 1])
    {
        string = string + 1;
        string[l - 2] = '\0';
        testPalindrome(string);
    }
    else
        return 0;
}

/**
 * @brief  allows the user to input a string
 *
 * @param str - the char array to be modifed to hold the user's input
 */
void getUserString(char str[])
{
    char chr;
    int i =0;
    while((chr = getchar()) != '\n')
    {
        if(isalpha(chr)) // only allow alpha numeric chars
        {
            str[i++] = tolower(chr);
        }
    }
}

/**
 * @brief - Print the results of the palindrome test
 *
 * @param str the string tested to be a palindrome
 */
void results(char str[])
{
    if(testPalindrome(str))
    {
        printf("The string %s is a palindrome", str);
    }
    else {
        printf("The string %s is not a palindrome", str);
    }
}
