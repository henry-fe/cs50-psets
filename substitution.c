#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
bool verifyKeyLength(string key, int alphabetLength);
bool verifyIfOnlyAlphabetical(string key, int alphabetLength);
bool verifyNoDuplicates(string key);
void lowerToUpper(string key, int alphabetLength);
void startEncrypting(string plainText, string key, int alphabetLength);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("error!\n");
        return 1;
    }
    string key = argv[1];
    int alphabetLength = 26;
    lowerToUpper(key, alphabetLength);
    if (verifyKeyLength(key, alphabetLength) && verifyIfOnlyAlphabetical(key, alphabetLength) &&
        verifyNoDuplicates(key))
    {
        string plainText = get_string("plaintext: ");
        startEncrypting(plainText, key, alphabetLength);
        return 0;
    }
    else
    {
        printf("error\n");
        return 1;
    }
}

bool verifyKeyLength(string key, int alphabetLength)
{
    int length = strlen(key);
    if (length != alphabetLength)
    {
        return false;
    }
    return true;
}

bool verifyIfOnlyAlphabetical(string key, int alphabetLength)
{
    for (int i = 0; i < alphabetLength; i++)
    {
        if (isalpha(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool verifyNoDuplicates(string key)
{
    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        int index = key[i] - 'A';

        if (seen[index])
        {
            return false;
        }

        seen[index] = true;
    }

    return true;
}

void lowerToUpper(string key, int alphabetLength)
{
    for (int i = 0; i < alphabetLength; i++)
    {
        key[i] = toupper(key[i]);
    }
}

void startEncrypting(string plainText, string key, int alphabetLength)
{
    int plainTextLength = strlen(plainText);
    int alphabetUpper = 65;
    int alphabetLower = 97;
    int index = 0;

    printf("ciphertext: ");

    for (int i = 0; i < plainTextLength; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                index = (int) plainText[i] - alphabetUpper;
                printf("%c", (char) key[index]);
            }
            else
            {
                index = (int) plainText[i] - alphabetLower;
                printf("%c", (char) key[index] + 32);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }

    printf("\n");
}
