#include <cs50.h>
#include <math.h>
#include <stdio.h>

int every_other_digit(long credit_card);
int multiplyandsum(int last_digit);
int number_of_digits(long credit_card);
bool valid_amex(long credit_card, int num_digits);
bool valid_master(long credit_card, int num_digits);
bool valid_visa(long credit_card, int num_digits);

int main(void)
{
    long credit_card = get_long("Card number: ");
    int num_digits = number_of_digits(credit_card);
    int sum_every_other_digit = every_other_digit(credit_card);
    bool amex = valid_amex(credit_card, num_digits);
    bool master = valid_master(credit_card, num_digits);
    bool visa = valid_visa(credit_card, num_digits);
    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
}

bool valid_amex(long credit_card, int num_digits)
{
    int first_digits = credit_card / pow(10, num_digits - 2);
    if ((num_digits == 15) && (first_digits == 34 || first_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool valid_master(long credit_card, int num_digits)
{
    int first_digits = credit_card / pow(10, num_digits - 2);
    if ((num_digits == 16) && (first_digits >= 51 && first_digits <= 55))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool valid_visa(long credit_card, int num_digits)
{
    int first_digits = credit_card / pow(10, num_digits - 1);
    if ((num_digits == 13 || num_digits == 16) && (first_digits == 4))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int number_of_digits(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        credit_card = credit_card / 10;
        count++;
    }
    return count;
}

int every_other_digit(long credit_card)
{
    int sum = 0;
    bool even_digit = false;
    while (credit_card > 0)
    {
        if (even_digit == true)
        {
            int last_digit = credit_card % 10;
            int product = multiplyandsum(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
        }
        even_digit = !even_digit;
        credit_card /= 10;
    }
    return sum;
}

int multiplyandsum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply /= 10;
    }
    return sum;
}
