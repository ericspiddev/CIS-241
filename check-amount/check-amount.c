#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 6
#define TENSLENGTH 11
#define ONESLENGTH 9


char *less_ten[]= {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

char *less_twenty[] = {
    "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
};

char *ten_multiples[] =
{
    " ", " ", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"
};

void getCheckAmount(char []);
void splitAmount(char* d , char* c , char* a);
void determineDollars(char ones[], char tens[], char dollars[]);
int determineCents(char cents[]);
void printAmount(int cents, char ones[], char tens[]);


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

void getCheckAmount(char checkAmount[])
{
    double amount = 0.0;
    int scanned = 1;
    do{
        fflush(stdin);
        printf("Welcome please enter a check amount from 0.00 to 99.99: ");
        scanned = scanf(" %lf", &amount);
        printf("Scanned is %d\n", scanned);
    }while(amount > 99.99 || amount < 0.0 || scanned == 0);
    printf("User entered amount of %0.3lf\n", amount);
    gcvt(amount, 4, checkAmount);
}

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

void determineDollars(char ones[], char tens[], char dollars[])
{
    if(strlen(dollars) == 1)
    {
       strcpy(ones, less_ten[atoi(dollars)]);
    }
    else{
        if(dollars[0] == '1')
        {
            strcpy(tens, less_twenty[atoi(dollars) - 10]);
        }

        else{
            strcpy(tens, ten_multiples[dollars[0] - '0']);
            if(dollars[1] != '0')
            {
            strcpy(ones, less_ten[dollars[1] - '0']);

            }
        }
    }
}

int determineCents(char cents[])
{
   return atoi(cents);
}

void printAmount(int cents, char ones[], char tens[])
{
    if(strcmp(ones, "\0") == 0)
    {
        printf("%s ", tens);
    }
    else if(strcmp(tens, "\0") == 0)
    {
        printf("%s ", ones);
    }
    else{
        printf("%s %s ", tens, ones);
    }
    printf("and %d/100\n", cents);
}