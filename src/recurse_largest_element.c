#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list_t
{
    int value;
    struct list_t* next;
} list_t;

list_t* make_list (int n)
{
    list_t* list = NULL;
    for (int i = 0; i < n; ++i)
    {
        list_t* old_list = list;
        list = malloc (sizeof *list);
        if (list)
        {
            list->value = rand () % 1000;
            list->next = old_list;
        }
        else
            break;
    }
    return list;
}

int list_max (list_t* list)
{
    if (list->next == NULL)
        return list->value;
    int max_rest = list_max (list->next);
    return max_rest > list->value ? max_rest : list->value;
}

int main ()
{
    srand (time (0));

    int n = 1000;
    list_t* list = make_list (n);

    if (list)
    {
        list_t* start = list;
        while (start != NULL)
        {
            printf ("%d\n", start->value);
            start = start->next;
        }

        printf ("Maximum of list is %d\n", list_max (list));
        return 0;
    }
    else
        return -1;
}
