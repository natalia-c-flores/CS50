#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2 )
    {
        printf("Please enter just one positive number.\n");
        return 1;
    }
    
    // int key_lenght = strlen(argv[1]);
    
    // for(int i = 0; i < key_lenght; i++)
    // {
    //     char n = argv[1][i];
    //     if(!isdigit(n))
    //     {
    //         printf("Usage:./caesar key\n");
    //         return 1;
    //     }
    //     else
    //     {
            
    //     }
    // }

    int k = atoi(argv[1]);
    if (k > 0)
    {
        string plain_text = get_string("Enter a plain text:");
        int total_chars = strlen(plain_text);
        char cipher_text[total_chars];
        int sum = 0;
        for (int i=0; i < (total_chars); i++ )
        {
            int c = plain_text[i];
            if (isalpha(c) && isupper(c))
            {
                int r = k % 26;
                sum = c + r;
                if (sum > 'Z' && k < 26)
                {
                    if (k < 26)
                    {
                        int bla = 26 - k;
                        sum = c - bla;
                    }
                    else
                    {
                        int bla = 26 - r;
                        sum = c - bla;
                    }
                }
                cipher_text[i] = sum;

            }
            else if (isalpha(c) && islower(c))
            {
                int r = k % 26;
                sum = c + r;
                if (sum > 'z')
                {
                    if (k < 26)
                    {
                        int bla = 26 - k;
                        sum = c - bla;
                    }
                    else
                    {
                        int bla = 26 - r;
                        sum = c - bla;
                    }
                }
                cipher_text[i] = sum;
            }
            else
            {
                cipher_text[i] = c;
            }
        }
        printf("Ciphertext:%s\n", cipher_text);
        return 0;
    }
    else if (k == 0)
    {
        printf("Usage:./caesar key\n");
        return 1;
    }
    else if (k < 0)
    {
        printf("Please enter just one positive number.\n");
        return 1;
    }
}