/**
 * Author: Eric Spidle
 * Class: CIS 241-01
 * Instructor: Professor Bhuse
 * Input: 20 integers
 * Output: The smallest integer that was put in
 * Description: The user inputs 20 integer values and those value are stored in an array
 *  than the smallest of those is printed to the screen
 */
#include <stdio.h> // lib needed for printing

#define READ_SIZE 20 // number of integers to read

void readInput(int arr [], int size); // fxn prototypes
int getMin(int arr[], int size);
void printArr(int arr[], int size);

/**
 * @brief The entry point of the program and where all the function calls happen
 *
 * @return int returns 0 when finished executing
 */
int main(void)
{
    int numArr[READ_SIZE] = {0}; // array to hold the user input
    printf("Input 20 numbers\n");
    readInput(numArr, READ_SIZE);
    printArr(numArr, READ_SIZE);
    printf("Smallest number in the array is %d\n", getMin(numArr,READ_SIZE)); // print smallest number
    return 0;
}

/**
 * @brief
 *
 * @param arr - the array that will be used to store the integers
 * @param size - the size of the array
 */
void readInput(int arr [], int size)
{
    for(int i = 0; i < size; i++) // loop for going through the array
    {
        printf("Number %d: ",i + 1); // print prompt showing current number
        scanf("%d", arr + i); // take in user input
    }
}

/**
 * @brief output array so use can see all numbers that were input
 *
 * @param arr - the array to be printed
 * @param size - the size of the array
 */
void printArr(int arr[], int size)
{
    printf("---------------Array---------------");
    for(int i =0; i< size; i++)
    {
        if(i % 5 ==  0) // every 5 elements newline
            printf("\n");
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}
/**
 * @brief return the minimum value that is in the array 'arr'
 * @param arr - array to be searched through for a minimum value
 * @param size - the size of the array
 * @return int - the minimum value in the array
 */
int getMin(int arr[], int size)
{
    int min = arr[0];
    for(int i =0 ; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
