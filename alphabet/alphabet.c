#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string line = get_string("Type characters: ");
    int length = strlen(line);

    for (int i = 0; i < length; i++)
    {
        if (line[i] <= line [i - 1])
        {
            printf ("NO\n");
            return 0;
        }
    }
    printf ("YES\n");

}
