#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);

int main(void)
{
    string txt;
    txt = get_string("Text: ");
    int letters = count_letters(txt);
    int words = count_words(txt);
    int sentence = count_sentences(txt);

    float L = (double)letters / (double)words * (double)100;
    float S = (double)sentence / (double)words * (double)100;
    float index0 = (double)0.0588 * L - (double)0.296 * S - (double)15.8;
    int index = round(index0);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 15)
    {
        printf("Grade %i\n", index);

    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string txt)
{
    int letters = 0;
    int leng = strlen(txt);

    for (int i = 0; i < leng ; i++)
    {
        if (txt[i] >= 65 && txt[i] <= 90)
        {
            letters++;
        }

        if (txt[i] >= 97 && txt[i] <= 122)
        {
            letters++;
        }
    }
    return letters;

}

int count_words(string txt)
{
    int words = 1;
    int leng = strlen(txt);

    for (int i = 0; i < leng ; i++)
    {
        if (txt[i] == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string txt)
{
    int sentences = 0;
    int leng = strlen(txt);

    for (int i = 0; i < leng ; i++)
    {
        if (txt[i] == 33 || txt[i] == 46 || txt[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}