#include <stdio.h>


float getUsingPercentG();
float getUsingPercentE();
float getUsingPercentF();

int main(void)
{
    float percentG = getUsingPercentG();
    float percentF = getUsingPercentF();
    float percentE = getUsingPercentE();
    printf("Percent G is %g\n", percentG);
    printf("Percent F is %f\n", percentF);
    printf("Percent E is %E\n", percentE);
    return 0;
}

float getUsingPercentG()
{
    float value = 0;
    printf("Enter value 1.2345 to be read by %%g specifer: ");
    scanf("%g", &value);
    return value;
}


float getUsingPercentF()
{
    float value = 0;
    printf("Enter value 1.2345 to be read by %%f specifer: ");
    scanf("%f", &value);
    return value;
}

float getUsingPercentE()
{
    float value = 0;
    printf("Enter value 1.2345 to be read by %%e specifer: ");
    scanf("%E", &value);
    return value;
}