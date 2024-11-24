#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate (char p, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string pt = get_string("Plaintext:  ");
    printf("Ciphertext: ");

    for (int i = 0; i < strlen(pt); i++)
    {
        pt[i] = rotate(pt[i], key);
        printf("%c", pt[i]);
    }
    printf("\n");
    return 0;
}

bool only_digits(string text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate (char p, int k)
{
    char c;
    if (isupper(p))
    {
        p = p-65;
        c = (p + k)%26;
        c += 65;
    }
    else if (islower(p))
    {
        p = p-97;
        c = (p + k)%26;
        c += 97;
    }
    else
    {
        return p;
    }
    return c;
}
