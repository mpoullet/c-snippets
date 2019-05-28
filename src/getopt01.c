#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int use_hd = 0;

int main (int argc, char* argv[])
{
    while (1)
    {
        static struct option long_options[] = {
            {"hd", no_argument, &use_hd, 1},
            {"sd", no_argument, &use_hd, 0},
            {0, 0, 0, 0}};

        int option_index = 0;
        int c = getopt_long_only (argc, argv, "", long_options, &option_index);

        if (c == -1)
            break;

        switch (c)
        {
        case 0:
            /* If this option set a flag, do nothing else now. */
            if (long_options[option_index].flag != 0)
                break;
            printf ("option %s", long_options[option_index].name);
            if (optarg)
                printf (" with arg %s", optarg);
            printf ("\n");
            break;

        case 'a':
            puts ("option -a\n");
            break;

        case '?':
            /* getopt_long already printed an error message. */
            break;

        default:
            abort ();
        }
    }

    if (use_hd)
        puts ("use_hd flag is set");

    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }
}
