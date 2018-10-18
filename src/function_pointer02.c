#include <stdio.h>

int add (int a, int b)
{
    return a + b;
}

/* common syntax */
int function_pointer_as_parameter_1 (int (*function) (int a, int b), int a, int b)
{
    return function (a, b);
}

/* alternative syntax */
int function_pointer_as_parameter_2 (int function (int a, int b), int a, int b)
{
    return function (a, b);
}

int main (void)
{
    const int a = 1;
    const int b = 2;
    printf ("%d\n", function_pointer_as_parameter_1 (add, a, b));
    printf ("%d\n", function_pointer_as_parameter_2 (add, a, b));
}
