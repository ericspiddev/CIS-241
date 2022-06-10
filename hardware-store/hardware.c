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
#define HEADER "%-10s\t%-20s\t%-10s\t%-4s\n" //header specifier string
#define FORMATSTRING "%-10d\t%-20s\t%-10d\t%5.2f\n" // each record entry specifier string


//record data to be added to the file
int recordNumbers[NUM_RECORDS] = {3, 17, 24, 39, 56, 68, 77, 83};
char* toolNames[NUM_RECORDS] = {"Electric Sander", "Hammer", "Jig Saw", "Lawn Mower", "Power Saw", "Screwdriver", "Sledge Hammer", "Wrench"};
int quantity[NUM_RECORDS] = {7, 76, 21, 3, 18, 106, 11, 34};
double cost[NUM_RECORDS] = {57.98, 11.99, 11.00, 79.50, 99.99, 6.99, 21.50, 7.50};

FILE* openFile(char fileName[], char mode[]);
void printHeader(FILE* fptr);
int checkFilePtr(FILE* fptr); // function prototypes
void printRecords(FILE* fptr);

/**
 * @brief the main function of the program that executes the other fxns
 * @return int- returns 0 when program is done with execution
 */
int main(void)
{
    FILE* fptr = openFile(FILENAME, WRITE);
    printHeader(fptr);
    printRecords(fptr);
    fclose(fptr);
}

/**
 * @brief - this function opens a file and returns the file pointer
 *
 * @param fileName - The name (or path) of the file to be opened
 * @param mode - what mode the file should be opened in (write, read, append...)
 * @return FILE* - the file pointer that references the file just opened
 */
FILE* openFile(char fileName[], char mode[])
{
    return fopen(fileName, mode); // return the file
}

/**
 * @brief -this prints the header row into the file for the rest of the data to follow suit
 *
 * @param fptr - the file to write the header into
 */
void printHeader(FILE* fptr)
{
    if(checkFilePtr(fptr) == 1) // if fptr is not null
    {
        fprintf(fptr, HEADER, "Record #", "Tool name", "Quantity", "Cost"); // print the header to the file
    }
}

/**
 * @brief - this prints the records to file in each row
 *
 * @param fptr - the file to print the data too.
 */
void printRecords(FILE* fptr)
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
 * @brief - Checks the fptr to see if it poinmts to a file or
 * if the fptr is null
 *
 * @param fptr - the fptr to be checked
 * @return int - return 1 if the fptr is not null and 0 if it is null
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