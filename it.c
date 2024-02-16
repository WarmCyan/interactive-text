#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/246127/why-is-volatile-needed-in-c
// unclear if volatile needed here
// const char *volatile raw_text = "";


char* ReadFile(char* filename)
{
    // creates a buffer to read the entire file into and then returns that
    // buffer
    
    // https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
    char *buffer = NULL;
    int string_size, read_size;
    
    FILE *handler = fopen(filename, "r");

    // first we find the total file size so we know how big of a buffer to
    // create
    fseek(handler, 0, SEEK_END);
    string_size = ftell(handler);
    rewind(handler);

    buffer = (char*) calloc(string_size + 1, sizeof(char));

    read_size = fread(buffer, sizeof(char), string_size, handler);

    if (string_size != read_size)
    {
        free(buffer);
        buffer = NULL;
        printf("Failed to read file, size read does not match file size");
    }

    fclose(handler);

    return buffer;
}


/* nope */
char *ParseInteractiveSpots(char* text)
{
    char *delim = "\\t";
    char *token = strtok(text, delim);
    while (token) {
        puts(token);
        token = strtok(NULL, delim);
    }

    return NULL;
}


char *FindNextInteractiveSpot(char *text)
{
    char *delim = "\\t";
    char *next = strstr(text, delim);

    /* int len = next - text; */
    /* puts(itoa(len)); */
    /* sprintf(&len, "%d", 42); */
    ptrdiff_t length = next - text;
    /* printf("text: %p, next: %p, dist: %td", text, next, next - text); */
    printf("%d\n", length);
    puts(next);
    return next;
}


int main(int argc, char **argv)
{
    // I want to read in a file and display it
    if (argc < 2) {
        printf("Please specify file with bar text");
        exit(1);
    }
    char* filename = argv[1];
    printf("Reading from ");
    printf(filename);
    printf("\n");

    char* text = ReadFile(filename);
    printf(text);

    /* char* spots = ParseInteractiveSpots(text); */
    /* printf(spots); */
    FindNextInteractiveSpot(text);
}
