//including files
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{

    string k = argv[1];
    int d;

    if (argc == 2)//checking no. of arguments
    {
        for (int j = 0; j < strlen(k); j++)//verifying key is pure character
        {

            if (!isalpha(k[j]))
            {
                return 1;
            }

        }
        for (int b = 0; b < strlen(k); b++)//making key in lower case
        {
            if (isupper(k[b]))
            {
                k[b] = ((int)k[b] + 32);
            }
        }

    d = get_int("enter 1 for encoding 2 for decoding\n");

    string plaintext = get_string("plaintext: ");//getting plaintext
    if(d==1)
        {
        for (int i = 0, c = 0; i < strlen(plaintext) && c < strlen(plaintext); i++, c++)//encoding
        {

            if (isupper(plaintext[i]))
            {
                plaintext[i] = (((int)plaintext[i] - 65) + ((int)k[c % strlen(k)] - 97)) % 26 + 65;

            }
            else if (islower(plaintext[i]))
            {
                plaintext[i] = (((int)plaintext[i] - 97) + ((int)k[c % strlen(k)] - 97)) % 26 + 97;

            }
            else
            {
                c -= 1;//excluding special char eg.$ % &
            }

        }
            printf("encoded text: %s\n", plaintext);//output
    }
    else
    {
    for (int i = 0, c = 0; i < strlen(plaintext) && c < strlen(plaintext); i++, c++)//decoding
        {

            if (isupper(plaintext[i]))
            {
                plaintext[i] = (((int)plaintext[i] - 65) - ((int)k[c % strlen(k)] - 97)) % 26 + 65;

            }
            else if (islower(plaintext[i]))
            {
                plaintext[i] = (((int)plaintext[i] - 97) - ((int)k[c % strlen(k)] - 97)) % 26 + 97;

            }
            else
            {
                c -= 1;//excluding special char eg.$ % &
            }

        }
            printf("decoded text: %s\n", plaintext);//output
    }


    }




    else
    {
        return 1;
    }

}
