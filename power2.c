#include <stdio.h>

unsigned int power2(unsigned int number, unsigned int pow);
void printBinary(unsigned int num);

int main(void)
{
    unsigned int number = 0;
    unsigned int pow = 0;
    unsigned int result = 0;
    printf("Enter a number to be multiplied by a power of 2: ");
    scanf("%u", &number);
    printf("Enter the power of 2 to multiply %d by: ", number);
    scanf("%u", &pow);
    result = power2(number, pow);
    printf("%u multiplied by 2 to the power of %u is %u\n",number, pow, result);
    printf("%u in binary is ", result);
    printBinary(result);
    printf("\n");
    return 0;
}


unsigned int power2(unsigned int number, unsigned int pow)
{
    return  number *  (2 << pow - 1);
}

void printBinary(unsigned int num)
{
    if(num > 1) // if we have not hit 0 yet
        printBinary(num/2); // call the function again taking off another place in the number
    printf("%d", num % 2); // when we hit 0 we break the recursion by printing 0 and then each number proceeds to be either 1 or 0
}