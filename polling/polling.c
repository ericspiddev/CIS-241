/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: Ratings for the various prompts provided to the user(s)
 * Outputs: A table of the polling results as well as some stats about the results
 * Description: This function allows multiple people to take a survey on GVSU campus issues
 * they find important. This can be done for as many people as needed until the user enters r
 * once the survey is filed
 ***/

#include<stdio.h> // libs used for this
#include<stdlib.h>

#define TOPIC_NUM 5
#define MAX_RATING 10 // macros for array sizes
#define NUM_USERS 5

int pollUser(int res[TOPIC_NUM][MAX_RATING],  char** topics);
void printResults(int res[TOPIC_NUM][MAX_RATING], char** topics, int count);
int getTotal(int res[MAX_RATING]);                                               //function prototypes
void getMinAndMax(int data[TOPIC_NUM][MAX_RATING], int * mindex, int *maxdex, int* min, int * max);

/**
 * @brief the main portion of the program that calls all the functions
 *
 * @return int returns 0 when execution is done
 */
int main(void)
{
    int responses[TOPIC_NUM][MAX_RATING] = {0}; // array for responses
    char* topics[TOPIC_NUM]; // array for topics
    topics[0] = "Parking";
    topics[1] = "Campus Dining";  // topics
    topics[2] = "Student Life";
    topics[3] = "School Spirit";
    topics[4] = "Education";
    printf("----------Campus Polling----------\n");
    int surveys =  pollUser(responses, topics);
    printResults(responses, topics, surveys);
    return 0;
}

/**
 * @brief - Prompts the user to enter a rating for each of the 5 topics listed above
 * this can be done until the user clicks r to print the results
 * @param res - array to store results in
 * @param topics - list of topics to prompt the user with
 * @return int number of surveys taken
 */
int  pollUser(int res[TOPIC_NUM][MAX_RATING], char** topics)
{
    int rate = 0;
    int count = 0;
    char choice = 0;
    do{
        printf("Rate the following topics on a scale from 1(least important) to 10(most important) for you as a GVSU Student\n");
        for(int i =0; i< TOPIC_NUM; i++)
        {
            printf("%s ", topics[i]);
            scanf("%d", &rate);
            while ((getchar()) != '\n'); // clear the buffer
            if(rate >= 1 && rate <= 10)
            {
                res[i][rate - 1]++;
            }
            else
            {
                printf("Invalid rating please use 1-10\n");
                i--;
            }
        }
    printf("Results recorded thank you for your time!\n");
    printf("Press any key to survey again or r to print responses ");
    scanf("%c", &choice);
    while ((getchar()) != '\n'); // clear the buffer
    count++;
    }while(choice != 'r');
    return count;
}

/**
 * @brief - This function is used to print the results for the survey(s) it provides
 * the average, most and least important and a table showing all the voting that occured
 * @param res - the results array
 * @param topics - the list of topics voted on
 * @param count - the total number of surveys completed
 */
void printResults(int res[TOPIC_NUM][MAX_RATING], char** topics, int count)
{
    int max =9;
    int min =0;
    int  mindex = 0;
    int maxdex = 0; // used for min and max calculations
    printf("\t\t\t\t==========Polling Results==========\n");
    printf("\t\t");
    for(int l =1; l <=10; l++){
        printf("%d\t", l);
    }
    printf("Average");
    printf("\n\t\t---------------------------------------------------------------------------\n");
    for(int i =0; i < TOPIC_NUM; i++)
    {
        printf("%s  \t", topics[i]);
        for(int j = 0; j < MAX_RATING; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("%0.3lf", (double)getTotal(res[i]) / count); // go through row and get the average voting value
        printf("\n");
    }
    getMinAndMax(res, &mindex, &maxdex, &min, &max); //  get the  least and most important issue and their score
    printf("The most important issue was %s with a score of %d\n", topics[maxdex], max);
    printf("The least important issue was %s with a score of %d\n", topics[mindex], min);
}

/**
 * @brief  Returns the total of all integers in an array. In this case each row of results
 * is passed into this function to help calculate the average and determine the most and
 * least important issues
 * @param res - the result's row
 * @return int - return the total sum of the votes
 */
int getTotal(int res[10])
{
    int total = 0;
    for(int i =0; i < MAX_RATING; i++){
        total += res[i] * (i + 1); // this considers the weight of each score as well
    }
    return total;
}

/**
 * @brief Finds the min and max total values as well as the index for each that way their respective topic
 * can be printed to the user
 * @param data - the results to be scanned for min and max
 * @param mindex - the topic index of the least important issue
 * @param maxdex - the topic index of the most important issue
 * @param min - the minimum or least points value
 * @param max - the max or greatest points value
 */
void getMinAndMax(int data[TOPIC_NUM][MAX_RATING], int * mindex, int *maxdex, int* min, int * max)
{
    *max = getTotal(data[0]); // init both max and min to 0 to start
    *min  = getTotal(data[0]);
    for(int i =1; i < TOPIC_NUM; i++) // start at 1 since we already have 0 in max and min
    {
        int currtotal = getTotal(data[i]); // assign the total and then compare
        if(currtotal > *max)
        {
            *maxdex = i;
            *max = currtotal;
        }
        else if(currtotal < *min)
        {
            *mindex = i;
            *min = currtotal;
        }

    }
}