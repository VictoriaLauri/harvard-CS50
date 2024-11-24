#include <cs50.h>
#include <stdio.h>

int fib(int number);

int main(void)
{
    int input;
    do
    {
        input = get_int("Enter a number of terms: ");
    }
    while (input < 1);

    printf("%i\n", fib(input));
    return 0;
}

int fib(int number)
{
    if (number == 1)
        return 0;

    if (number == 2)
        return 1;

    return number = fib(number - 1) + fib(number - 2);
}
