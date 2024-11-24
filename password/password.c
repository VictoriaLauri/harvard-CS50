#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_input(string);

int main(void)
{
    string input = get_string("Enter your password: ");

    bool check = check_input(input);

    if (check == true)
    {
        printf("Password is correct\n");
    }
    if (check == false)
    {
        printf("Password is incorrect\n");
    }
}

bool check_input (string user_input)
{
    string password = "Open";

    if (strcmp (password, user_input) == 0)
    {
        return true;
    }
    return false;
}
