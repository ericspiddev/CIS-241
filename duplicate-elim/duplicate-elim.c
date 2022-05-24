/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: None
 * Outputs: 20 random numbers from 1 to 20 and then print distinct values from those random numbers
 * Description: Generates 20 random numbers from 1 to 20 and then puts distinct values from the
 * random numbers into an array that is the exact size needed for all the distinct values
 ***/
#include <stdio.h>
#include <stdlib.h> // libraries needed for the program to work
#include <time.h>

#define MAX 20 // max number for random range
#define MIN 1 // min number for random range

int generateNums(int max, int min, int *arr, int size);
void printArray(int *arr, int size);   //  fxn prototypes
int alreadyInArr(int *array, int value, int size);

/**
 * @brief The main execution point for the program this calls all the needed function
 *
 * @return int returns 0 when execution is done
 */
int main(void)
{
    printf("Generating 20 random numbers from 1 to 20....\n");
    int *numbers;
    int size = 1;
    numbers = (int *)calloc(size, sizeof(int)); // allocate memory for array starting with 1 index
    srand(time(0)); // seed the random number generator
    size = generateNums(MIN, MAX, numbers, size); // call the number generator
    printArray(numbers, size); // print the distinct arrays
    free(numbers); // free the memory we allocated for the distinct array
    return 0; //program over
}

/**
 * @brief - Prints the array passed to the function in this case it is the distinct array
 *
 * @param arr - the array to be printed
 * @param size - the size of the array that is to be printed
 */
void printArray(int *arr, int size)
{
    printf("\nDistinct values from the 20 generated numbers: \n");
    for (int i = 0; i < size; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}

/**
 * @brief - Generate the random numbers from 1 to 20 and then populate
 * the distinct values into the array arr
 *
 * @param min - the bottom of the random number range
 * @param max - the top of the random number range
 * @param arr - the array that will be populated with distinct values
 * @param size - size of the array
 * @return int - returns the new size of the array after we are done inserting values
 */
int generateNums(int min, int max, int *arr, int size)
{
    printf("Original numbers: \n");
    size_t index = 0; // index variable
    for (int i = 0; i < max; i++)
    {
        int random = rand() % (max + 1 - min) + min;
        printf("%d  ",random);
        if (index == 0)
        {
            arr[index++] = random;
        }
        else if (!(alreadyInArr(arr, random, index)))
        {
            arr = (int *)realloc(arr, ++size * sizeof(int)); // add one spot to the array
            if (index <= (size) && index > 0)
            {
                arr[index++] = random; // add unique random number to array
            }
        }
    }
    return size;
}

/**
 * @brief - Helper function that checks to see if the value passed in is already in the passed in array
 *
 * @param array - the array to scan for the value
 * @param value - the value we are looking for in the array
 * @param size - size of array (sizeof does not work since the array is dynamically allocated)
 * @return int - 1 iif the item is already in the array and 0 if not
 */
int alreadyInArr(int *array, int value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value) // check if value is in array
            return 1; // return 1 if yes
    }
    return 0; // return 0 if we make it all the way through
}
