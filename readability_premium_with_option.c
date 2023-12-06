#include <stdio.h>
#include <math.h>

int main(void)
{
    input_text(); // input texts for checking Grade of readability
}

void input_text()
{
    char text[3000]; // max 3000 char
    printf("Input Texts: \n");
    gets(text);

    text_formula(text);
}

void optionYesNo()
{
    char answer[10]; // max 10 char
    printf("\nWould you input texts again ? Enter Y or N: \n"); // Data type nya wajib string // Walau input dirampingkan dengan input 1 character 
    gets(answer);

    if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0) { // if (answer == 'Y') // STRING is so special in C language
        printf("\nOpening the app again.\n");
        printf("------------------------\n");
        input_text();
    } 
    else
    {
        printf("The app is closed.\n");
        return(0); // optional // closing program
    }
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
        optionYesNo();
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
        optionYesNo();
    }
    else
    {
        printf("Grade %i\n", index);
        optionYesNo();
    }
}
