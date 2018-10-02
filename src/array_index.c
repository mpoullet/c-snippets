// Can a const variable be used to declare the size of an array in C? https://stackoverflow.com/a/30312817/496459
// Can enum member be the size of an array in ANSI-C? https://stackoverflow.com/a/13770414/496459

#include <stdio.h>

int main (void)
{
    enum LENGTH
    {
        LENGTH = 10
    };
    int array[LENGTH];

    int array_len = sizeof (array) / sizeof (array[0]);

    printf ("array_len=%d\n", array_len);
    return 0;
}
