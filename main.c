#include <stdio.h>

// Function prototype for lexical analyzer
void analyzer(char *input);

int main(int argc, char *argv[])
{
    FILE *fp;// File pointer
    char line[1000]; // Buffer to store each line from file

    if(argc != 2)  // Check whether source file name is present
    {
        printf("Not enough arguments\n");
        return 1;
    }

      // Open source file in read mode
    fp = fopen(argv[1], "r");

    // Check if file is opened successfully
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

     // Read the file line by line
    while(fgets(line, sizeof(line), fp))
    {
         // Send each line for lexical analysis
        analyzer(line);
    }

      // Close the file
    fclose(fp);

    return 0;
}