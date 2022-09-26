#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool IsConvertable(string key_in_string);
int cipher(char letter, int key);

int main(int argc, string argv[])
{
    string key_str;
    int key;
    if (argc == 2)
    {
        key_str = argv[1];
    }
    else
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }

    // Check if the key is a valid value

    //Check if all entered digits are convertable to int

    // If all digits are convertable
    if (IsConvertable(key_str))
    {
        key = atoi(key_str);
    }

    // If not all digits are convertable
    else
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int l = strlen(plaintext);
    char ciphered[l];

    printf("ciphertext: ");

    for (int i = 0; i < l; i++)
    {
        if (isalpha(plaintext[i]))
        {
            ciphered[i] = cipher(plaintext[i], key);
            printf("%c", cipher(plaintext[i], key));
        }
        else
        {
            ciphered[i] = plaintext[i];
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

//Check if String is convertable an int
bool IsConvertable(string key_in_string)
{
    for (int i = 0, l = strlen(key_in_string); i < l; i++)
    {
        if (!isdigit(key_in_string[i]))
        {
            return false;
        }
    }
    return true;
}


int cipher(char letter, int key)
{
    char char_local;
    if (isupper(letter))
    {
        char_local = letter - 65;
        if (char_local + key > 25)
        {
            char_local = (char_local + key) % 26;
            letter = char_local + 65;
            return letter;
        }
        if (char_local + key < 25)
        {
            char_local = char_local + key;
            letter = char_local + 65;
            return letter;
        }
    }
    if (islower(letter))
    {
        char_local = letter - 97;
        if (char_local + key > 25)
        {
            char_local = (char_local + key) % 26;
            letter = char_local + 97;
            return letter;
        }
        if (char_local + key < 25)
        {
            char_local = char_local + key;
            letter = char_local + 97;
            return letter;
        }
    }
    return 0;
}