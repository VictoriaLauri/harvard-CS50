#include <cs50.h>
#include <stdio.h>

bool triangle_check (int a, int b, int c);

int main(void)
{
    int x = get_int("Triangle side 1 length: ");
    int y = get_int("Triangle side 2 length: ");
    int z = get_int("Triangle side 3 length: ");

    if (triangle_check(x, y, z) == false)
    {
        printf ("Triangle invalid\n");
    }
    if (triangle_check(x, y, z) == true)
    {
        printf ("Triangle valid\n");
    }
}

bool triangle_check (int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return false;
    }
    return true;
}
