#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check_key(string key);
char convert (char c, char k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid command\n");
        return 1;
    }
    if (check_key(argv[1]) == false)
    {
        printf("Invalid number or mix of characters\n");
        return 1;
    }

    string pt = get_string("Plaintext:  ");

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(pt); i++)
    {
     if (islower(pt[i]))
     {
        int ct = pt[i] - 97;
        printf("%c", argv[1][ct] + 32);
     }
     else if (isupper(pt[i]))
     {
        int ct = pt[i] - 65;
        printf("%c", argv[1][ct]);
     }
     else printf("%c", pt[i]);
    }
    printf("\n");

    return 0;
}

bool check_key(string key)
{
    int len = strlen(key);
    if (len != 26)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        key[i] = toupper(key[i]);
        for (int j = i+1; j < len; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}


