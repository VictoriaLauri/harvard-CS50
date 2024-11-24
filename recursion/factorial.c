#include <cs50.h>
#include <stdio.h>

int factorial (int number);

int main(void)
{
    int input = get_int("Enter a number: ");

    printf("%i\n", factorial(input));
}

int factorial (int number)
{

    if (number == 1)
    {
        return 1;
    }

    for (int i = number; i > 1; i--)
    {
        number *= i-1;
    }
    return number;
}


//alternative would be to use a recursion here as follows
//after the if statement and instead of a loop we just insert the below
//return number * factorial(number - 1);
//this will work because the if statement is the base case
