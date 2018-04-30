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
