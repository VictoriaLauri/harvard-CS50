#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int stpop;
    do
    {
        stpop = get_int("Enter the starting population of lamas: ");
    }
    while (stpop < 9);

    int endpop;
    do
    {
        endpop = get_int("Enter the end population of lamas: ");
    }
    while (endpop < stpop);

    int years = 0;
    while (stpop < endpop)
    {
        stpop += stpop / 12;
        years++;
    }
    printf ("Years: %i\n", years);


}
