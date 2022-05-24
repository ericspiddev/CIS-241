#include<stdio.h>
#include<stdlib.h>

#define TOPIC_NUM 5
#define MAX_RATING 10

void pollUser(int res[TOPIC_NUM][MAX_RATING],  char** topics);
void printResults(int res[TOPIC_NUM][MAX_RATING], char** topics);


int main(void)
{
    int results[TOPIC_NUM][MAX_RATING] = {0};
    char* topics[TOPIC_NUM]; // array for topics
    topics[0] = "topic1";
    topics[1] = "topic2";
    topics[2] = "topic3";
    topics[3] = "topic4";
    topics[4] = "topic5";
    pollUser(results, topics);
    printResults(results, topics);
    return 0;
}

void greetUser()
{
    printf("----------Polling----------\n");

}

void pollUser(int res[TOPIC_NUM][MAX_RATING], char** topics)
{
    int rate = 0;
    printf("Rate the following topics on a scale from 1(least important) to 10(most important)\n");
    for(int i =0; i< TOPIC_NUM; i++)
    {
        printf("%s ", topics[i]);
        scanf("%d", &rate);
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
    printf("Press c to continue or r to print results\n");
}

void printResults(int res[TOPIC_NUM][MAX_RATING], char** topics)
{
    printf("\t\t\t\t==========Polling Results==========\n");
    printf("\t");
    for(int l =1; l <=10; l++){
        printf("%d\t", l);
    }
    printf("\n\t---------------------------------------------------------------------------\n");
    for(int i =0; i < TOPIC_NUM; i++)
    {
        printf("%s\t", topics[i]);
        for(int j = 0; j < MAX_RATING; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}
