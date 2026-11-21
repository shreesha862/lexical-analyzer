#include <string.h>
#include "keyword.h"

// Function to check whether a token is a keyword
int keyword(char *str)
{
    // Data type keywords
    char *datatype[] =
    {
        "int","char","float","double","void","long","short"
    };

    // Storage class keywords
    char *storage[] =
    {
        "auto","register","static","extern"
    };

    // Control statement keywords
    char *controlstatement[] =
    {
        "if","else","for","while","do","switch","case","break","continue","return"
    };

    // Check for data type keywords
    for(int i = 0; i < 7; i++)
    {
        if(strcmp(str, datatype[i]) == 0)
            return 1;
    }

    // Check for storage class keywords
    for(int i = 0; i < 4; i++)
    {
        if(strcmp(str, storage[i]) == 0)
            return 2;
    }

    // Check for control statement keywords
    for(int i = 0; i < 10; i++)
    {
        if(strcmp(str, controlstatement[i]) == 0)
            return 3;
    }

    // Not a keyword
    return 0;
}