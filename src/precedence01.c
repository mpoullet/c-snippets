// https://stackoverflow.com/a/30662456
// http://en.cppreference.com/w/c/language/operator_precedence

#include <stdio.h>

struct S
{
    int a;
};

int main (void)
{
    struct S my_s = {.a = 2};

    struct S* p_my_s = &my_s;

    /* same precedence, but from left to right */
    p_my_s->a++;
    printf ("p_my_s->a++: %d\n", p_my_s->a);

    (p_my_s->a)++;
    printf ("(p_my_s->a)++: %d\n", p_my_s->a);

    /* different precedence */
    ++p_my_s->a;
    printf ("++p_my_s->a: %d\n", p_my_s->a);

    ++(p_my_s->a);
    printf ("++(p_my_s->a): %d\n", p_my_s->a);

    return 0;
}
