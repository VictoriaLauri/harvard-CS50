#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int hash = 1; hash <= height; hash++)      // controls the number of rows
    {                                               // all this happens inside the row
        int dots = height - hash;
        for (int dot = 0; dot < dots; dot++)        // controls the number of spaces in each row
        {
            printf(" ");
        }
        for (int dot = 0; dot < hash; dot++)        // controls the number of hashes in each row
        {
            printf("#");
        }

        printf ("  ");                              // after each row add 2 x spaces

        for (int dot = 0; dot < hash; dot++)        // controls the number of hashes in each row
        {
            printf("#");
        }

        printf("\n");                               // and lastly add the line break
    }
}
