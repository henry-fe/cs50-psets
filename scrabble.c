#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getPoints(string word);

int main()
{
    string player1_word = get_string("Player 1, type a word! \n");
    string player2_word = get_string("Player 2, type a word! \n");
    int player1_points = getPoints(player1_word);
    int player2_points = getPoints(player2_word);
    if (player1_points > player2_points)
    {
        printf("Player 1 wins! \n");
    }
    else if (player2_points > player1_points)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
    return 0;
}

int getPoints(string word)
{

    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int asciiOffset[2] = {-65, -97};
    int charPosition;
    int length = strlen(word);
    int sum_points = 0;

    for (int i = 0; i < length; i++)
    {
        charPosition = word[i];
        if (isupper(word[i]))
        {
            sum_points += points[charPosition + asciiOffset[0]];
        }
        else if (islower(word[i]))
        {
            sum_points += points[charPosition + asciiOffset[1]];
        }
    }
    return sum_points;
}
