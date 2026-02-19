#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int getWords(string text);
int getSentences(string text);
int getLetters(string text);
void indexColemanLiau(float W, float S, float L);

int main()
{
    string text = get_string("Text: ");
    int words = getWords(text);
    int sentences = getSentences(text);
    int letters = getLetters(text);
    indexColemanLiau(words, sentences, letters);
    return 0;
}

int getWords(string text)
{

    int length = strlen(text);
    int words = 1;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    return words;
}

int getSentences(string text)
{
    int length = strlen(text);
    int sentences = 0;
    int asciiOfmark;
    for (int i = 0; i < length; i++)
    {
        asciiOfmark = text[i];
        if (asciiOfmark == 33 || asciiOfmark == 63 || asciiOfmark == 46)
        {
            sentences += 1;
        }
    }
    return sentences;
}
int getLetters(string text)
{

    int length = strlen(text);
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if (isupper(text[i]))
        {
            letters += 1;
        }
        else if (islower(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

void indexColemanLiau(float wordCount, float sentenceCount, float letterCount)
{
    letterCount = (letterCount / wordCount) * 100;
    sentenceCount = (sentenceCount / wordCount) * 100;
    float index = 0.0588 * letterCount - 0.296 * sentenceCount - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int index_round = round(index);
        if (index_round >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index_round);
        }
    }
}
