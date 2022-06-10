/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: A unsigned integer value
 * Outputs: The input number in binary and then the reverse of that number
 * Description: This program prompts the user to enter a integer number and then
 * prints the binary version of that number to the user. This number is then printed again
 * this time reversing the bits. So user input of 10 would give:(1010) ===> (0101)
 */
#include<stdio.h>

int getNumber(void);
void printBinary(unsigned int num); // function prototypes
void reverseBits(unsigned int num);

/**
 * @brief Main function of the program that controls the flow
 * and calls all the other functions
 * @return int - returns 0 to indicate successful execution
 */
int main(void)
{
    unsigned int inputNum = 0;
    inputNum = getNumber();
    printf("You put in %d \n", inputNum);
    printf("The number %d in binary is: ", inputNum);
    printBinary(inputNum);
    printf("\n");
    printf("The reverse of that in binary is: ");
    reverseBits(inputNum);
    return 0;
}

/**
 * @brief Prompt the user to enter a number and then store that number in the passed in variable value
 * @param num - the number that will hold the value for the user
 */
int getNumber(void)
{
    int hold = 0;
    printf("Input a number to reverse the order of the bits. ");
    scanf("%d", &hold);
    return hold;
}

/**
 * @brief Print the passed in integer in binary form
 * @param num  the number to be printed in binary.
 */
void printBinary(unsigned int num)
{
    if(num > 1) // if we have not hit 0 yet
        printBinary(num/2); // call the function again taking off another place in the number
    printf("%d", num % 2); // when we hit 0 we break the recursion by printing 0 and then each number proceeds to be either 1 or 0
}

/**
 * @brief - This prints the bits of the number in reverse order so 10(1010) would be (0101)
 * @param num - the number to be reversed
 */
void reverseBits(unsigned int num)
{
    while(num > 0) // while we are bigger than 0
    {
        printf("%d", num & 1); // print num & with the 1's place
        num >>= 1; // left shift number
    }
    printf("\n");
}