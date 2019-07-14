#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char x[6] = {'\0','\0','\0','\0','\0','\0'};
int main(int argc, char * argv[])
{
    //Confirms a hash has been provided.
    if (argc < 1)
    {
        printf("Please run program with hash e.g. ./crack ab4DPi7vp71Xc");
        return 1;
    }
    //Stores the first two chars from the hash and teminates with a null character.
    char salt[3] = {argv[1][0],argv[1][1], '\0'};

    //Continually compares the output of crypt and the current value of x and salt with the provided hash while the 6th character in x is null terminating character.
    void inc_letter(char s[], int i);
        do
        {
            if(strcmp(crypt(x, salt), argv[1]) == 0)
            {
                printf("Plaintext: %s\n", x);
                return 0;
            }
            //Calls the function inc_letter providing the index 0.
            inc_letter(x, 0);

        }while(x[5] == '\0');

    printf("Oh Dear!");

    return 0;
}
void inc_letter(char w[], int i)
{
    //If provided "string" at index i contains '\0' set it to 'A';
    if(w[i] == '\0')
    {
        w[i] = 'A';
    }
    //If provided "string" at index i contains 'z' set it to 'A' and call the itself increasing index by 1;
    else if(w[i] == 'z')
    {
        w[i] = 'A';
        inc_letter(w, i + 1);
    }
    //If provided "string" at index i contains 'Z' set it to 'a', imprives performance by only using alphabet;
    else if (w[i] == 'Z'){
        w[i] = 'a';
    //if all others doe not equal false simply increment the provided string at the provided index by one i.e. a to b.
    }else{
        w[i]++;
    }
}