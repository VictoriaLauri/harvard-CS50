#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string name = get_string ("What is your name? ");
    string age = get_string ("How old are you? ");
    string phone = get_string ("What is your phone number? ");
    printf("Name is %s.\nAge is %s.\nPhone number is %s.\n", name, age, phone);
}
