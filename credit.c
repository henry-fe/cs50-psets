#include <cs50.h>
#include <stdio.h>

bool validateCardNumber(unsigned long long number)
{
    int x = 0; // obtains the not summed numbers
    int y = 0; // get the summed numbers
    int v;     // verifies if double number > 9 to apply luhn's algoritm correctly
    int i = 0;
    int total_sum;
    while (number > 0)
    {
        if (i % 2 == 0)
        {
            x = x + (number % 10);
            number = number / 10;
            i = i + 1;
        }
        else
        {
            if ((number % 10) * 2 > 9)
            {
                v = number % 10 * 2;
                v = v % 10 + 1;
                number = number / 10;
                y = y + v;
                v = 0;
                i = i + 1;
            }
            else
            {
                y = y + (number % 10) * 2;
                number = number / 10;
                i = i + 1;
            }
        }
    }
    total_sum = x + y;
    return (total_sum % 10 == 0);
}

int getCardPrefix(unsigned long long number)
{
    while (number >= 100)
    {
        number = number / 10;
    }
    if (number >= 40 && number <= 49) // used for VISA
    {
        number = number / 10;
    }
    return number;
}

void printCardType(int number, unsigned long long l)
{
    int lenght = 0;
    while (l > 0)
    {
        l = l / 10;
        lenght += 1;
    }

    int prefix = number;
    if (prefix == 4 && (lenght == 13 || lenght == 16))
    {
        printf("VISA\n");
    }
    else if ((prefix == 34 || prefix == 37) && lenght == 15)
    {
        printf("AMEX\n");
    }
    else if (prefix >= 51 && prefix <= 55 && lenght == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main()
{
    unsigned long long cardnumber = get_long("Digite o número do cartão: ");
    if (validateCardNumber(cardnumber))
    {
        printCardType(getCardPrefix(cardnumber), cardnumber);
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
