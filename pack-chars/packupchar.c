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
void getUserChars(char[]);
void printCharAsByte(char c);
void printStringAsBytes(char chars[]);
void printIntAsBytes(unsigned int num);


int main(void)
{
    char userChars[NUM_CHARS + 1];
    unsigned int packedChars = 0;
    printf("Enter four characters to be packed into an unsigned integer: ");
    scanf("%s", userChars);
    printStringAsBytes(userChars);
    packedChars = packChars(userChars);
    printIntAsBytes(packedChars);
    return 0;
}


void printStringAsBytes(char chars[])
{
    for(int i =0; i < NUM_CHARS; i++)
        printCharAsByte(chars[i]);
}

void printIntAsBytes(unsigned int num)
{
   for(int i = (BYTE_SIZE * 4) - 1; i >= 0; i--)
    {
        printf("%d", (num & (1 << i)) >> i); // 0100_0001
        if(i % 8 == 0 && i != 0)
        {
            printf("_");
        }
    }
    printf("\n");
}

void printCharAsByte(char c) //0000_0000
{
    printf("Char %c in binary is ",c);
    for(int i = BYTE_SIZE - 1; i >= 0; i--)
    {
        printf("%d", (c & (1 << i)) >> i); // 0100_0001
        
    }
    printf("\n");
}

/**
 * @brief
 *
 * @param chars
 * @return unsigned int
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