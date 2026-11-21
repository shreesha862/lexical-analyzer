#include <stdio.h>
#include <ctype.h>
#include "keyword.h"

// Function to analyze each line of input
void analyzer(char *input)
{
    char buffer[100]; // Buffer to store tokens
    int i = 0;//Buffer index

       // Traverse each character in the input string
    for(int j = 0; input[j] != '\0'; j++)
    {
        char ch = input[j];

        // Collect letters, digits and underscore
        if(isalnum(ch) || ch == '_')
        {
            buffer[i++] = ch;
        }
        else
        {
            // Process token stored in buffer
            if(i != 0)
            {
                buffer[i] = '\0'; //Converts character array into a string.

                // Check whether token is a keyword
                int k = keyword(buffer);

                if(k == 1)
                    printf("Data type keyword: %s\n", buffer);
                else if(k == 2)
                    printf("Storage type keyword: %s\n", buffer);
                else if(k == 3)
                    printf("Control type keyword: %s\n", buffer);
                else if(isdigit(buffer[0]))
                    printf("Constant: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);

                i = 0; //reset the buffer to collect the nxt token
            }

            // Check delimiters and braces
            if(ch == '(')
                printf("Open BRACE: (\n");
            else if(ch == ')')
                printf("Close BRACE: )\n");
            else if(ch == '{')
                printf("Open Curly BRACE: {\n");
            else if(ch == '}')
                printf("Close Curly BRACE: }\n");
            else if(ch == ';')
                printf("Delimiter: ;\n");

                // Check operators
            else if(ch == '+' || ch == '-' || ch == '*' ||
                    ch == '/' || ch == '=' || ch == '<' ||
                    ch == '>' || ch == '&' || ch == '|')
            {
                // Get next character
                char next = input[j + 1];

                // Relational operators
                if((ch == '=' && next == '=') ||
                   (ch == '<' && next == '=') ||
                   (ch == '>' && next == '='))
                {
                    printf("Relational Operator: %c%c\n", ch, next);
                    j++;
                }
                     // Increment and decrement operators
                else if((ch == '+' && next == '+') ||
                        (ch == '-' && next == '-'))
                {
                    printf("Increment/Decrement Operator: %c%c\n", ch, next);
                    j++;
                }
                // Logical operators
                else if((ch == '&' && next == '&') ||
                        (ch == '|' && next == '|'))
                {
                    printf("Logical Operator: %c%c\n", ch, next);
                    j++;
                }
                   // Single-character operators
                else
                {
                    printf("Single Operator: %c\n", ch);
                }
            }
        }
    }

    // Process the last token present in buffer
    if(i != 0)
    {
        buffer[i] = '\0';

        int k = keyword(buffer);

        if(k == 1)
            printf("Data type keyword: %s\n", buffer);
        else if(k == 2)
            printf("Storage type keyword: %s\n", buffer);
        else if(k == 3)
            printf("Control type keyword: %s\n", buffer);
        else if(isdigit(buffer[0]))
            printf("Constant: %s\n", buffer);
        else
            printf("Identifier: %s\n", buffer);
    }
}