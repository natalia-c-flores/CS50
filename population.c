#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startsize;        
    do
    {
        startsize = get_int("Enter a start size:");
    }
    while (startsize < 9);
    // TODO: Prompt for end size
    int endsize;
    do
    {
        endsize = get_int("Enter an end size:");
    }
    while (endsize < startsize);

    // TODO: Calculate number of years until we reach threshold
    int result = startsize;
    int years = 0;
    while (result < endsize)
    {
        result = result + result / 3 - result / 4;
        years++;
    }
    // TODO: Print number of years
    if (result >= endsize)
    {
        printf("Years: %i", years);
    }
}
    