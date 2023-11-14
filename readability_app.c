#include <stdio.h>
#include <math.h>

int main(void)
{

    char text[1000];
    strcpy(text, input_text()); // Copy string 1 to string 2

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
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

void input_text()
{
    // Prompt user
    char inp_text[1000]; // max 1000 char
    printf("Input Texts: ");
    gets(inp_text);
}
