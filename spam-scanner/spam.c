/*
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: An email written by the user
 * Outputs: A spam score for the email guessing how likely the email is spam
 * Description: The user is prompted to enter an email they wrote or received and then
 * using the 30 most common phrases
***/
#include <string.h>
#include <stdio.h> // libs used for program
#include <ctype.h>


#define EMAIL_SIZE 1000 // max email size
#define SPAM_SIZE 30 // amount of words in spam list

void getUserEmail(char []);
int scoreEmail(char *spam[], char email[]);
void printScore(int score);

char *spam[]  = {
    "as seen on", "buy",
    "near you", "meet singles",
    "double your", "earn extra cash",
    "extra income", "opportunity",
    "work at home", "while you sleep",
    "cash", "credit",
    "discount", "free",
    "lowest price", "eliminate debt",
    "stock pick", "debt",
    "click here", "click below",
    "sale", "big sale",
    "guarantee", "winner",
    "you won", "you have been selected",
    "sign up free", "call now",
    "limited time", "now",
};// list of 30 spam phrases
/**
 * @brief The main entry point of the program this calls all of the functions
 *
 * @return int - returns 0 when done executing
 */
int main(void)
{
    char userEmail[EMAIL_SIZE];
    printf("Enter an email message to be graded for spam ");
    getUserEmail(userEmail);
    int score = scoreEmail(spam, userEmail);
    printScore(score);
    return 0;
}

/**
 * @brief - take in the user's email message and assign each char to a spot in the email string
 * any character over the limit of the array size gets truncated off
 * @param email -the string to hold each char of the user's email
 */
void getUserEmail(char email [])
{
    int i = 0;
    while(i != EMAIL_SIZE)
    {
        char c = getchar();
        if(c == '\n') // if newline break
            break;
        else
        {
            email[i++] = tolower(c); // lower case everything for comparison
        }
    }
}

/**
 * @brief - This function is responsible for assigning a score to the user's inputted email
 * to check and see if what was entered is actually spam or not
 *
 * @param spam the list of spam words to check the email for
 * @param email - the email string provided by the user
 * @return int the score given to the email based on the likelihood it is spam
 */
int scoreEmail(char *spam[], char email[])
{
    int score = 0;
    char emailCopy[strlen(email)];
    strcpy(emailCopy, email);
    for(int i =0; i < SPAM_SIZE; i++)
    {
        int needleSize = strlen(spam[i]);
       char* str = strstr(email, spam[i]);
        while(str != NULL)
        {
            score++;
            str +=  needleSize;
            str = strstr(str, spam[i]);
        }
        strcpy(emailCopy, email);
    }
    return score;
}

/**
 * @brief This prints to the user the likelihood that the message they received is spam or not
 *
 * @param score the number of spam phrases that were detected
 */
void printScore(int score)
{
    printf("%d spam phrases detected\n", score);
    if(score < 4)
    {
        printf("This is probably not spam\n");
    }
    else if(score < 10)
    {
        printf("There is a good chance this is spam\n");
    }
    else
    {
        printf("This is almost certainly spam\n");
    }
}