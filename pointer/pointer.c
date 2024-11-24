#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;

    *c = 14;
    c = &b;
    *c = 25;

    printf("a value is: %i, address is %p\n", a, &a);
    printf("b value is: %i, address is %p\n", b, &b);
    printf("c value is: %p, address is %p\n", c, &c);

}
