/***
 * Name: Eric Spidle
 * Course: CIS-241-01
 * Instructor: Professor Bhuse
 * Inputs: operation choice, 2 numbers to be added, subtracted multiplied or divided
 * Outputs: The 2 numbers that we put in and the result from the operation on those numbers
 * Description: Allows the user to enter a choice for addition, subtraction, multiplication,
 * or division and then lets the user input two numbers to perform that operation on
 ***/

#include <stdio.h>
#include <stdlib.h>

#define OPNUM 4 // macro for number of operations

void greetUser();
void add(double, double);
void subtract(double, double);
void multiply(double, double); // fxn prototypes
void divide(double, double);
void getValues(double * , double *);

// enum made to show clearly how each operation is selected
enum Choices{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

/**
 * @brief the main flow of the program that handles the users choice
 *
 * @return int when done executing we returns 0
 */
int main(void)
{
    double a, b = 0.0; // values to be used for calculations
    void(*ops[OPNUM])(double,  double) = {add, subtract, multiply, divide}; // array of fxn pointers
    char choice = 0; // char for holding ascii value of user's choice
    greetUser(); // greet the user and layout options
    while((choice = getchar()) != 'q')
    {
        int chartoInt = choice - '0';
        if(choice != '\n')
        {
            switch (chartoInt)
            {
            case ADD:
                printf("Adding\n");
                getValues(&a, &b);
               (*ops[chartoInt])(a, b);
                break;
            case SUBTRACT:
                printf("Subtracting\n");
                getValues(&a, &b);
                (*ops[chartoInt])(a, b);
                break;
            case MULTIPLY:
                printf("Multiplying\n");
                getValues(&a, &b);
                (*ops[chartoInt])(a, b);
                break;
            case DIVIDE:
                printf("Dividing\n");
                getValues(&a, &b);
                (*ops[chartoInt])(a, b);
                break;
            default:
                printf("Invalid operation choice. Valid choices are 0,1,2,3\n");
                break;
            }
        printf("Operation complete enter 0, 1, 2 or 3 to perform another calculation or press q to quit\n");
        }
    }
}

/**
 * @brief - function just to greet the user and provide options for the calculator
 *
 */
void greetUser()
{
  printf("-----------Calculator-----------\n");
  printf("Pick one of the following operations: \n");
  printf("0) Add\n");
  printf("1) Subtract\n");
  printf("2) Multiply\n");
  printf("3) Divide\n");
}

/**
 * @brief - function to add two numbers
 *
 * @param a - the first number to be added
 * @param b - the second number to be added
 */
void add(double a, double b)
{
    printf("Adding %0.2f and %0.2f\n", a, b);
    printf("%0.2f + %0.2f = %0.2f\n", a, b, a + b);

}


/**
 * @brief - function to subtract two numbers
 *
 * @param a - the first number  (a - b)
 * @param b - the second number (a - b)
 */
void subtract(double a, double b)
{
    printf("Subtracting %0.2f from %0.2f\n", a, b);
    printf("%0.2f - %0.2f = %0.2f\n", a, b, a - b);
}

/**
 * @brief - function to multiply two numbers
 *
 * @param a - the first number  (a * b)
 * @param b - the second number (a * b)
 */
void multiply(double a, double b)
{
    printf("Multiplying %0.2f by %0.2f\n", a, b);
    printf("%0.2f * %0.2f = %0.2f\n", a, b, a * b);
}
/**
 * @brief - function to divide two numbers
 *
 * @param a - the first number  (a / b)
 * @param b - the second number (a / b)
 */
void divide(double a, double b)
{
    printf("Divding %0.2f by %0.2f\n", a, b);
    printf("%0.2f / %0.2f = %0.2f\n", a, b, a / b);
}

/**
 * @brief Prompt the user to enter two numbers that will have the selected mathematic operation performed on them
 *
 * @param aptr - pointer used to hold the first value input by the user
 * @param bptr - pointer used to hold the first value input by the user
 */
void getValues(double * aptr , double * bptr)
{
    printf("Enter first number : ");
    scanf("%lf", aptr);
    printf("Enter second number : ");
    scanf("%lf", bptr);
}