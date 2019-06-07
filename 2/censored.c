#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REPLACEMENT "CENSORED"
#define BUFFER_SIZE (1024)

int main(int argc, char *argv[])
{
    size_t bytes_read;
    char *s, *line = malloc(BUFFER_SIZE);
    size_t nbytes = BUFFER_SIZE, replacement_length = strlen(REPLACEMENT);

    // read from stdin
    while ((bytes_read = getline(&line, &nbytes, stdin)) != -1)
    {  
        // scanning and replacing specified words
        for (int i = 1; i < argc; i++)
        {
            while ((s = strstr(line, argv[i])) != NULL)
            {
                size_t search_length = strlen(argv[i]);
                size_t tail_length = strlen(s + search_length);

                (void) memmove(s + replacement_length, s + search_length, tail_length + 1);
                (void) memcpy(s, REPLACEMENT, replacement_length);
            }
        }

        // display the result in output screen
        (void) fputs(line, stdout);
    }

    free(line);
}
