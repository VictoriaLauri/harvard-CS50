#include <cs50.h>
#include <stdio.h>

int add_two(int a, int b);

int main(void)
{
    int x = get_int ("Int x: ");
    int y = get_int ("Int y: ");

    int z = add_two(x, y);
    printf("The sum of %i and %i is %i\n", x, y, z);
}

int add_two(int a, int b)
{
    return a + b;
}
