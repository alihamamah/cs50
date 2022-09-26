#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char undercase_char(char c);
char uppercase_char(char c);
bool check_for_alpha(char c);
char cipher_char(char c, string key, string alphabet);

int main(int argc, string argv[])
{
    // limiting etries to 1
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // checking if the key contains the considered number of letters of the alphabet
    string key = argv[1];
    int l = strlen(key);
    if (l != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // checking if every character added in key is an alphabetic character
    for (int i = 0; i < l; i++)
    {
        if (!check_for_alpha(key[i]))
        {
            printf("Key contains character(s) that is/are not alphabetic character\n");
            return 1;
        }
    }
    //Checking if values added to key are repeated
    for (int i = 0; i < l; i++)
    {
        int temp = key[i];
        for (int j = i + 1; j < l; j++)
        {
            int temp0 = i;
            while (temp0 + 1 < l)
            {
                if (key[i] == key[j] || key[i] == key[j] + 32 || key[j] == key[i] + 32)
                {
                    printf("a value is allowed only once\n");
                    return 1;
                }
                temp0++;
            }
        }
    }
    // creating seperated key arrays for udercase and uppercase letters
    char undercased_key[l];
    char uppercased_key[l];
    string undercased_alphabet = ("abcdefghijklmnopqrstuvwxyz");
    string uppercased_alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    //filling both arrays with the values (udercase/uppercase letters)
    for (int i = 0; i < l; i++)
    {
        undercased_key[i] = undercase_char(key[i]);
    }
    for (int i = 0; i < l; i++)
    {
        uppercased_key[i] = uppercase_char(key[i]);
    }
    // asking user to enter plaintext
    string plaintext = get_string("plaintext:");
    // ciphering text
    int len = strlen(plaintext);
    char ciphertext[len];
    printf("ciphertext:");
    for (int i = 0; i < len; i++)
    {
        //keeping non-alphabetic character as they are and printing them on screen
        if (!check_for_alpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
            printf("%c", ciphertext[i]);
        }
        //ciphering uppercase letters and printing them on screen
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = cipher_char(plaintext[i], uppercased_key, uppercased_alphabet);
            printf("%c", ciphertext[i]);
        }
        //ciphering lowcase letters and printing them on screen
        if (ciphertext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = cipher_char(plaintext[i], undercased_key, undercased_alphabet);
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}
// to cipher character: find its index in alphabet and replace it with charectar located at the index in key
char cipher_char(char c, string key, string alphabet)
{
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        if (c == alphabet[i])
        {
            c = key[i];
            return c;
        }
    }
    return 0;
}
// make uppercase letters lowcase letters
char undercase_char(char c)
{
    if (c < 97)
    {
        c = c + 32;
    }
    return c;
}
// make lowcase letters uppercase letters
char uppercase_char(char c)
{
    if (c > 96)
    {
        c = c - 32;
    }
    return c;
}
// check if a character is alphabetic or not
bool check_for_alpha(char c)
{
    if (c < 'A')
    {
        return false;
    }
    if (c > 'Z' && c < 'a')
    {
        return false;
    }
    if (c > 'z')
    {
        return false;
    }
    else
    {
        return true;
    }
}
