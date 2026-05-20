#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void drawHangman(int lives)
{
    switch(lives)
    {
        case 6:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
            break;

        case 5:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
            break;

        case 4:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf(" |   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
            break;

        case 3:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
            break;

        case 2:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|\ |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
            break;

        case 1:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|\ |\n");
            printf("/    |\n");
            printf("     |\n");
            printf("=========\n");
            break;

        case 0:
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|\ |\n");
            printf("/ \\  |\n");
            printf("     |\n");
            printf("=========\n");
            break;
    }
}

int main()
{
    char words[][20] = {
        "APPLE",
        "MANGO",
        "COMPUTER",
        "PROGRAM",
        "TIGER",
        "ELEPHANT",
        "INDIA",
        "JAPAN"
    };

    int totalWords = 8;

    srand(time(0));

    int randomIndex = rand() % totalWords;

    char word[20];
    strcpy(word, words[randomIndex]);

    int length = strlen(word);

    char hidden[20];

    for(int i = 0; i < length; i++)
    {
        hidden[i] = '_';
    }

    hidden[length] = '\0';

    int lives = 6;
    int guessedLetters[26] = {0};

    printf("================================\n");
    printf("      HANGMAN WORD GAME\n");
    printf("================================\n");

    while(lives > 0 && strcmp(word, hidden) != 0)
    {
        drawHangman(lives);

        printf("\nWord: ");

        for(int i = 0; i < length; i++)
        {
            printf("%c ", hidden[i]);
        }

        printf("\n");

        printf("Lives Left: %d\n", lives);

        char guess;

        printf("Enter a letter: ");
        scanf(" %c", &guess);

        guess = toupper(guess);

        if(guess < 'A' || guess > 'Z')
        {
            printf("Please enter a valid alphabet.\n");
            continue;
        }

        if(guessedLetters[guess - 'A'] == 1)
        {
            printf("You already guessed this letter.\n");
            continue;
        }

        guessedLetters[guess - 'A'] = 1;

        int found = 0;

        for(int i = 0; i < length; i++)
        {
            if(word[i] == guess)
            {
                hidden[i] = guess;
                found = 1;
            }
        }

        if(found)
        {
            printf("Correct Guess!\n");
        }
        else
        {
            lives--;
            printf("Wrong Guess!\n");
        }
    }

    if(strcmp(word, hidden) == 0)
    {
        printf("\nCongratulations! You Won!\n");
        printf("The Word Was: %s\n", word);
    }
    else
    {
        drawHangman(0);

        printf("\nGame Over!\n");
        printf("The Correct Word Was: %s\n", word);
    }

    return 0;
}