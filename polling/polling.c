#include<stdio.h>
#include<stdlib.h>

#define TOPIC_NUM 5
#define MAX_RATING 10
#define NUM_USERS 5

int pollUser(int res[TOPIC_NUM][MAX_RATING],  char** topics);
void printResults(int res[TOPIC_NUM][MAX_RATING], char** topics, int count);
int getTotal(int res[MAX_RATING]);
void getMinAndMax(int data[TOPIC_NUM][MAX_RATING], int * mindex, int *maxdex, int* min, int * max);

int main(void)
{
    int responses[TOPIC_NUM][MAX_RATING] = {0};
    char* topics[TOPIC_NUM]; // array for topics
    topics[0] = "Parking";
    topics[1] = "Campus Dining";
    topics[2] = "Student Life";
    topics[3] = "School Spirit";
    topics[4] = "Education";
    int surveys =  pollUser(responses, topics);
    printResults(responses, topics, surveys);
    return 0;
}

void greetUser()
{
    printf("----------Campus Polling----------\n");

}

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
            while ((getchar()) != '\n');
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
    while ((getchar()) != '\n');
    count++;
    }while(choice != 'r');
    return count;
}

void printResults(int res[TOPIC_NUM][MAX_RATING], char** topics, int count)
{
    int max, min, mindex, maxdex = 0;
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
        printf("%0.3lf", (double)getTotal(res[i]) / count);
        printf("\n");
    }
    getMinAndMax(res, &mindex, &maxdex, &min, &max);
    printf("The most important issue was %s with a score of %d\n", topics[maxdex], max);
    printf("The least important issue was %s with a score of %d\n", topics[mindex], min);
}

int getTotal(int res[10])
{
    int total = 0;
    for(int i =0; i < MAX_RATING; i++){
        total += res[i] * (i + 1);
    }
    return total;
}

void getMinAndMax(int data[TOPIC_NUM][MAX_RATING], int * mindex, int *maxdex, int* min, int * max)
{
    *max = getTotal(data[0]);
    *min  = getTotal(data[0]);
    for(int i =1; i < TOPIC_NUM; i++)
    {
        int currtotal = getTotal(data[i]);
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