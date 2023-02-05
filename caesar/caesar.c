#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Let’s write a program called caesar that enables you to encrypt messages using Caesar’s cipher.

bool only_digits(string text);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    //User need too input a ./caesar key with a special key to be able to see a cripted message
    int k, length;
    string plaintext;
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    k = atoi(argv[1]);
    plaintext = get_string("plaintext: ");
    length = strlen(plaintext);
    char ciphertext[length + 1];
    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = rotate(plaintext[i], k);
    }
    ciphertext[length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool only_digits(string text)
{
    //Only digits could be the key for cripting
    int length;

    length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char p, int k)
{
    // Here we need to make a formula that chaning basic input to needed cipher
    char pi, c, ci;
    // For upper case we're using isupper
    if (isupper(p))
    {
        pi = p - 65;
        ci = (pi + k) % 26;
        c = ci + 65;
    }
    // For upper case we're using islower
    else if (islower(p))
    {
        pi = p - 97;
        ci = (pi + k) % 26;
        c = ci + 97;
    }
    else
    {
        return p;
    }
    return c;
}