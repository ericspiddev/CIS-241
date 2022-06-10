/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: None
 * Outputs: A file initialzed with the record contents shown in the homework doc
 * Description: This program uploads some hardcoded data to a record file using
 * FILE* fprintf. The exact record is found int the HW3S22 document
 */
#include <stdlib.h>
#include <stdio.h>  //libs used in program

#define WRITE "w"
#define APPEND "a"
#define READ "r"
#define FILENAME "records.dat" // macros used for easily changing file, record numbers, and formatting
#define NUM_RECORDS 8
#define HEADER "%-10s\t%-20s\t%-10s\t%-4s\n"
#define FORMATSTRING "%-10d\t%-20s\t%-10d\t%5.2f\n"


//record data to be added to the file
int recordNumbers[NUM_RECORDS] = {3, 17, 24, 39, 56, 68, 77, 83};
char* toolNames[NUM_RECORDS] = {"Electric Sander", "Hammer", "Jig Saw", "Lawn Mower", "Power Saw", "Screwdriver", "Sledge Hammer", "Wrench"};
int quantity[NUM_RECORDS] = {7, 76, 21, 3, 18, 106, 11, 34};
double cost[NUM_RECORDS] = {57.98, 11.99, 11.00, 79.50, 99.99, 6.99, 21.50, 7.50};

FILE* openFile(char fileName[], char mode[]);
void printHeader(FILE* fptr);
int checkFilePtr(FILE* fptr); // function prototypes
void printResults(FILE* fptr);

/**
 * @brief
 *
 * @return int
 */
int main(void)
{
    FILE* fptr = openFile(FILENAME, WRITE);
    printHeader(fptr);
    printResults(fptr);
    fclose(fptr);
}

/**
 * @brief
 *
 * @param fileName
 * @param mode
 * @return FILE*
 */
FILE* openFile(char fileName[], char mode[])
{
    return fopen(fileName, mode);
}

/**
 * @brief
 *
 * @param fptr
 */
void printHeader(FILE* fptr)
{
    if(checkFilePtr(fptr) == 1)
    {
        fprintf(fptr, HEADER, "Record #", "Tool name", "Quantity", "Cost");
    }
}

/**
 * @brief
 *
 * @param fptr
 */
void printResults(FILE* fptr)
{
    if(checkFilePtr(fptr) == 1)
    {
        for(int i =0; i < NUM_RECORDS; i++)
        {
            fprintf(fptr, FORMATSTRING,recordNumbers[i], toolNames[i], quantity[i], cost[i]);
        }
    }
    return;
}

/**
 * @brief
 *
 * @param fptr
 * @return int
 */
int checkFilePtr(FILE* fptr)
{
    if(fptr !=NULL)
        return 1;
    else
    {
        printf("Something went wrong opening the file please try again\n");
        return 0;
    }
}