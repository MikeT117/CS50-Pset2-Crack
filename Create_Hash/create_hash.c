#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// key = ab, plaintext = 'a' , Hash = abxxB7HlIeckU
int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Try Again\n");
    }
    printf("Test: %c\n", argv[1][0]);
    char *plaintext = crypt(argv[1], argv[2]);

    printf("%s\n",plaintext);
}