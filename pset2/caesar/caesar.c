#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
bool check_valid_key(string s);

int main(int argc, string argv[])
{
    //ensure that user provides a key and plain test

    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //extract key from user

    int key = atoi(argv[1]);

    string plaintext = get_string("plain text: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];

        //isalpha checks for alphabet characters

        if (isalpha(c))
        {
            char m = 'A';

            if (islower(c))
                //m is a modifier. It modifies the cipher formular to handle keys greater than 25

                 m = 'a';
            printf("%c", (c - m + key) % 26 + m);

        }
        else

            printf("%c", c);
    }
    printf("\n");

}

bool check_valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}