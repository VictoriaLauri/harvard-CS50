#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate president = get_candidate("Enter a candidate ");

    printf("Candidate created\n");
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Enter name: ");
    c.votes = get_int("Enter the number of votes: ");

    return c;
}
