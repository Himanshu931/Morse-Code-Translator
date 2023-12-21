#include <stdio.h>
#include <string.h>
#include <ctype.h>

void TextToMorse(char text[])
{
    char *Morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        char ch = tolower(text[i]);
        if (ch == ' ')
        {
            printf(" | ");
        }
        else if (isalpha(ch))
        {
            printf("%s ", Morse[ch - 'a']);
        }
    }
}

void MorseToText(char morse[])
{
    char *MorseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char *token = strtok(morse, " ");

    while (token != NULL)
    {
        if (strcmp(token, "|") == 0)
        {
            printf(" ");
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (strcmp(token, MorseCode[i]) == 0)
                {
                    printf("%c", letter[i]);
                    break;
                }
            }
        }

        token = strtok(NULL, " ");
    }
}

int main()
{
    char input[100];
    int option, repeat = 0;
    char choice[3];

    while (repeat == 0)
    {
        printf("\nChoose an option:\n");
        printf("1. Text to Morse Code\n");
        printf("2. Morse Code to Text\n");
        printf("Enter Your choice : ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            printf("Enter your Text: ");
            gets(input);
            printf("Morse Code: ");
            TextToMorse(input);
            break;

        case 2:
            printf("Enter your Morse Code: ");
            gets(input);
            printf("Text: ");
            MorseToText(input);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
        printf("Do you Want to Rerun the program? ");
        scanf("%s", choice);

        if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0)
        {
            repeat = 0;
        }
        else if (strcmp(choice, "No") == 0 || strcmp(choice, "no") == 0 || strcmp(choice, "NO") == 0)
        {
            printf("Exiting....");
            repeat = 1;
            break;
        }
    }
    return 0;
}
