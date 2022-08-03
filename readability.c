#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letter_counter(string Text);
int word_counter(string Text);
bool ishyphen(int element);
bool isapostrophe(int element);
int sentence_counter(string Text);
bool ispunctu(int element);
float letters_per_100words(string Text);
float sentences_per_100words(string Text);
float coleman_liau(float L, float S);

int main(void)
{
    string Text = {get_string("Text:")};
    int letters = letter_counter(Text);
    int words = word_counter(Text);
    int sentences = sentence_counter(Text);
    float L = letters_per_100words(Text);
    float S = sentences_per_100words(Text);
    int grade = coleman_liau(L, S);
    if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}

int letter_counter(string Text)
{
    int total_chars = strlen(Text);
    int non_letters = 0;
   
    for (int i = 0; i < total_chars; i++)
    {
        if (!isalpha(Text[i]))
        { 
            non_letters++;
        }
        
    }
    
    return total_chars - non_letters;
}
        
int word_counter(string Text)
{
    int words = 0;
    int total_chars = strlen(Text);
    char previous_element;
    
    for (int i = 0; i < total_chars; i++)
    {
        int element = Text[i];
        if (i > 0)
        {
            previous_element = Text[i - 1];
        }
        
        if (isalpha(previous_element) && (!isalpha(element)) && (!ishyphen(element)) && (!isapostrophe(element)))
        {
            words++;
        }
    }
    return words;
}

bool ishyphen(int element) //checks if an element of a text is a hyphen.
{
    bool ishyphen = element == '-';

    return ishyphen;
}

bool isapostrophe(int element) //checks if an element of a text is an apostrophe.
{
    bool isapostrophe = element == '\'';
    
    return isapostrophe;
}

int sentence_counter(string Text)
{
    int sentences = 0;
    int total_chars = strlen(Text);
    for (int i = 0; i < total_chars; i++)
    {
        int element = Text[i];
        if (ispunctu(element))
        {
            sentences++;
        }
    }
    return sentences;
}

bool ispunctu(int element)
{
    bool ispunctu = element == 33 || element == 46 || element == 63;
 
    return ispunctu;
}

float letters_per_100words(string Text)
{
    float total_words = word_counter(Text);
    float total_letters = letter_counter(Text);
    float letters_per_100 = 100 * (total_letters / total_words);
    return letters_per_100;   
}

float sentences_per_100words(string Text)
{
    float total_words = word_counter(Text);
    float total_sentences = sentence_counter(Text);
    float sentences_per_100 = 100 * (total_sentences / total_words);
    return sentences_per_100;   
}

float coleman_liau(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}
