#include <stdio.h>
#include <math.h>

int main(void)
{
    input_text(); // input texts for checking Grade of readability
}

void input_text()
{
    char text[3000]; // max 3000 char
    printf("Input Texts: ");
    gets(text);

    text_formula(text);
}

void text_formula(char text[])
{
    // String length
    int i = strlen(text);
    int letters = 0;
    int words = 1; // To account for last word
    int sentences = 0;

    // Loop for counting
    for (int x = 0; x < i; x++)
    {
        // Counting letters
        char c = text[x];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        // Counting words
        if (c == ' ')
        {
            words++;
        }

        // Counting Sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calculation
    float L = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8; // Coleman-Liau index formula
    int index = round(subindex);
    if (index > 16)
    {
        printf("Grade 16+\n");
        input_text();
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
        input_text();
    }
    else
    {
        printf("Grade %i\n", index);
        input_text();
    }
}
