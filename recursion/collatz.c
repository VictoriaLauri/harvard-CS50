#include <cs50.h>
#include <stdio.h>

int collatz(int number);

int main(void)
{
    int input;
    do
    {
        input = get_int("Enter a number: ");
    }
    while (input < 1);

    printf("Number of steps: %i\n", collatz(input));
    return 0;
}

int collatz(int number)
{
    if (number == 1)
        return 0;

    if ((number % 2) == 0)
        return 1 + collatz(number/2);

    else
        return 1 + collatz(number * 3 + 1);
}
