#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int getNumLetters(string text);
int getNumSentences(string text);
int getNumWords(string text);
int getGradeLevel(int numLetters, int numSentences, int numWords);
void printGradeLevel(int gradeLevel);


int main(int argc, string argv[])
{
    // Get input from user
    string text = get_string("Text: ");

    int numLetters = getNumLetters(text);
    int numSentences = getNumSentences(text);
    int numWords = getNumWords(text);

    int gradeLevel = getGradeLevel(numLetters, numSentences, numWords);

    printGradeLevel(gradeLevel);

}

void printGradeLevel(int gradeLevel)
{
    // Print the output: Grade X
    // Before Grade 1, 1-16, Grade 16+
    if (gradeLevel <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }
}

int getGradeLevel(int numLetters, int numSentences, int numWords)
{
    float S = (numSentences / (float)numWords) * 100;

    float L = (numLetters / (float)numWords) * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}

int getNumLetters(string text)
{
    // Count the number of letters
    int numLetters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Lower and upper case aA to zZ
        // Word is a sequence of characters separated by spaces
        if (isalpha(text[i]))
        {
            numLetters += 1;
        }
    }
    return numLetters;
}
// Count the number of sentences
int getNumSentences(string text)
{
    int numSentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Any occurrence of a period, exclamation point, or question mark indicates indicates the end of sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numSentences += 1;
        }
    }
    return numSentences;
}
// Get number of Words
int getNumWords(string text)
{
    int numWords = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            numWords += 1;
        }
    }
    return numWords + 1;
}