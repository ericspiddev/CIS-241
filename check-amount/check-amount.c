/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: A float between 0.00 and 99.99
 * Outputs: The text version of the float like you would see written on a check
 * Description: The user is prompted to enter a check amount in float form. This value is then given back to them in
 * text form much like you would see written on a check
 ***/
#include <stdio.h>
#include <stdlib.h> // libs needed for program
#include <string.h>

#define LENGTH 6
#define TENSLENGTH 11 //macros used for string lengths
#define ONESLENGTH 9


char *less_ten[]= {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
}; // array that holds 0 -9 in text form

char *less_twenty[] = {
    "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
}; // array that holds 10 - 19 in text form

char *ten_multiples[] =
{
    " ", " ", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"
}; // array that holds multiples of ten >= 20

void getCheckAmount(char []);
void splitAmount(char* d , char* c , char* a);
void determineDollars(char ones[], char tens[], char dollars[]); // fxn prototypes
int determineCents(char cents[]);
void printAmount(int cents, char ones[], char tens[]);

/**
 * @brief Main entry point for the program that handles execution and all function calls
 *
 * @return int returns 0 when done with execution
 */
int main(void)
{
    char checkAmount[LENGTH];
    char dollars[4];
    char cents[4];
    char dollarOnes[ONESLENGTH] = {0};
    char dollarTens[TENSLENGTH] = {0};

    getCheckAmount(checkAmount);
    splitAmount(dollars, cents, checkAmount);
    determineDollars(dollarOnes, dollarTens, dollars);
    printAmount(determineCents(cents), dollarOnes, dollarTens);
    return 0;
}

/**
 * @brief Prompts the user to enter an amount from 0.00 to 99.99
 *
 * @param checkAmount - the string that will hold the user's checkamount
 */
void getCheckAmount(char checkAmount[])
{
    double amount = 0.0;
    int scanned = 1;
    do{
        printf("Welcome please enter a check amount from 0.00 to 99.99: ");
        scanned = scanf(" %lf", &amount);
        while ((getchar()) != '\n'); // clear the buffer
    }while(amount > 99.99 || amount < 0.0 || scanned == 0);
    printf("User entered amount of %0.3lf\n", amount); // tell user what they entered
    gcvt(amount, 4, checkAmount); // convert float to string
}

/**
 * @brief  this function splits the amount
 *
 * @param d - the dollar portion of the amount
 * @param c - the cents portion of the amount
 * @param a - the total amount string
 */
void splitAmount(char* d, char* c, char a [] )
{
    int i =0;
    char* token = strtok(a, ".");
    while(token != NULL)
    {
        if(i == 0){
            strcpy(d, token);
            i++;
        }
        else{
            strcpy(c, token);
        }
        token = strtok(NULL, ".");
    }
}

/**
 * @brief - this function is used to determine the dollar amount in text based on the
 * ones and tens place of teh dollar string
 * @param ones - string to hold the ones place text
 * @param tens - string to hold the tens place text
 * @param dollars - total dollar string
 */
void determineDollars(char ones[], char tens[], char dollars[])
{
    if(strlen(dollars) == 1) //less than 10
    {
       strcpy(ones, less_ten[atoi(dollars)]);
    }
    else{
        if(dollars[0] == '1') // 10 - 19
        {
            strcpy(tens, less_twenty[atoi(dollars) - 10]);
        }

        else{ // 20-99
            strcpy(tens, ten_multiples[dollars[0] - '0']);
            if(dollars[1] != '0')
            {
            strcpy(ones, less_ten[dollars[1] - '0']);

            }
        }
    }
}

/**
 * @brief This returns the cent in the form of an in int
 *
 * @param cents - the string holding the cent value of the amount
 * @return int - the converted cents string in int form
 */
int determineCents(char cents[])
{
   return atoi(cents); // simply convert cent string to int and return it
}

/**
 * @brief - Used to print to the user the amount they entered in text form
 *
 * @param cents - the cents value
 * @param ones - the text form of the ones place in the dollar amount
 * @param tens - the text form of the tens place in the dollar amount
 */
void printAmount(int cents, char ones[], char tens[])
{
    if(strcmp(ones, "\0") == 0) // if no ones place string
    {
        printf("%s ", tens);
    }
    else if(strcmp(tens, "\0") == 0) // if no tens place string
    {
        printf("%s ", ones);
    }
    else{
        printf("%s %s ", tens, ones);
    }
    printf("and %d/100\n", cents); // print cents
}