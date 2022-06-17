/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: Four character values
 * Outputs: An unsigned int that has each character value packed into it.
 * Description: This program takes in user input for four ascii characters
 * then using
 ***/
#include <stdio.h> //libs needed for the program

#define NUM_CHARS 4 // macros
#define BYTE_SIZE 8


unsigned int packChars(char[]); // function prototypes
void promptUser(char arr[]);
void getUserChars(char[]);
void printCharAsByte(char c);
void printStringAsBytes(char chars[]);
void printIntAsBytes(unsigned int num);


/**
 * @brief the main function of the program that controls execution
 *
 * @return int - returns 0 when done executing
 */
int main(void)
{
    char userChars[NUM_CHARS + 1];
    unsigned int packedChars = 0;
    promptUser(userChars);
    printStringAsBytes(userChars);
    packedChars = packChars(userChars);
    printIntAsBytes(packedChars);
    return 0;
}

/**
 * @brief Function made to prompt the user for 4 characters
 *
 * @param arr - char array to store in the characters
 */
void promptUser(char arr[])
{
    printf("Enter four characters to be packed into an unsigned integer: ");
    scanf("%s", arr);
}

/**
 * @brief This prints each character in a string as its binary value
 *
 * @param chars - the string to be printed to bytes
 */
void printStringAsBytes(char chars[])
{
    for(int i =0; i < NUM_CHARS; i++) // for the total size of the string
        printCharAsByte(chars[i]); // call char byte print fxn
}

/**
 * @brief - this function takes in an unsigned integer and then prints it back in binary
 *
 * @param num - the unsigned int to be printed in binary
 */
void printIntAsBytes(unsigned int num)
{
   for(int i = (BYTE_SIZE * 4) - 1; i >= 0; i--)
    {
        printf("%d", (num & (1 << i)) >> i); // shift over check for 1 and shift back
        if(i % 8 == 0 && i != 0) // to seperate each byte we use a _ but we do not want one at 0
        {
            printf("_");
        }
    }
    printf("\n"); // print newline when done
}

/**
 * @brief - this function prints the passed in char ,c, as a binary
 * number
 *
 * @param c - the char to be printed in binary
 */
void printCharAsByte(char c)
{
    printf("Char %c in binary is ",c);
    for(int i = (BYTE_SIZE - 1); i >= 0; i--)
    {
        printf("%d", (c & (1 << i)) >> i); // shift over check for 1 amd then shift back so only 1 or 0 is printed
    }
    printf("\n");
}

/**
 * @brief - this function packs the four characters in the array into
 * an unsigned integer and then returns that value
 *
 * @param chars - the array of characters to be packed into an int
 * @return unsigned int - the chars packed into an unsigned integer
 */
unsigned int packChars(char chars[])
{
    unsigned int packedChars = chars[0];
    for(int i = 1; i < NUM_CHARS; i++)
    {
        packedChars <<= 8;
        packedChars |= chars[i];
    }
    return packedChars;
}