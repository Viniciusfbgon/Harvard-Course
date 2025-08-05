#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int count_letters = 0;
    int count_words = 1;
    int count_setences = 0;

    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            count_letters++;
        }
    }

    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i]))
        {
            count_words++;
        }
    }

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count_setences++;
        }
    }

    float calculation = (0.0588 * count_letters / count_words * 100) - (0.296 * count_setences / count_words * 100) - 15.8;
    int index = round(calculation);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}
