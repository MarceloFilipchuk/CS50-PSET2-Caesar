#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key;
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                key = atoi(argv[1]);
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    int character;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //checks if the character in the current array is an uppercase
        if (isupper(plaintext[i]))
        {    
            character =  plaintext[i] + key;
            if (character > 90)
            {
                // does a while loop in order to get the correct letter after it reached Z
                while (character > 90)
                {
                    character = 65 + (character % 91);
                }
                printf("%c", character);
            }
            else
            {
                printf("%c", character);
            }    
        }
        //checks if the character in the current array is an lowercase
        else if (islower(plaintext[i]))
        {    
            character =  plaintext[i] + key;
            if (character > 122)
            {
                // does a while loop in order to get the correct letter after it reached z     
                while (character > 122)
                {
                    character = 97 + (character % 123);
                }
                printf("%c", character);
            }
            else
            {
                printf("%c", character);
            }    
        }
        // this includes every symbols or spaces that are not letters and prints them unchanged
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}


