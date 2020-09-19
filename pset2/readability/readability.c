#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    string text = get_string("Text: ");

    int words_count, sentences_count, letters_count;

    words_count = sentences_count = letters_count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters_count++;
        }
        if ((i == 0 && text[i] != ' ') || (i != len - 1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            words_count++;
        }
        if (text[i] == '.' || text[i] ==  '?' || text[i] == '!')
        {
            sentences_count++;
        }

    }

    float L = ((letters_count) / (float) words_count) * 100;

    float S = ((sentences_count) / (float) words_count) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}