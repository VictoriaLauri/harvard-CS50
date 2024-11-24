#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height ");
    }
    while (n <= 0 || n > 8);

    for (int hash = 1; hash <= n; hash++)
    {
        int dots = n - hash;
        for (int dot = 0; dot < dots; dot++)
        {
            printf(" ");
        }
        for (int dot = 0; dot < hash; dot++)
        {
            printf("#");
        }
        printf("\n");
    }
}
