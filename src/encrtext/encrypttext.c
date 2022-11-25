#include "encrypttext.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int SALT = 2561;
int *passwd_crypted = NULL; //  These pointers are cleared in main
int *passwd_size = NULL; //  These pointers are cleared in main

void encrypt_text(char *ch)
{
    int passwd_int[64];
    passwd_crypted = (int*) malloc(sizeof(int) * 64);
    passwd_size = (int*) malloc(sizeof(int));
    *passwd_size = strlen(ch);
    if(passwd_crypted)
    {
        // convert to int
        for(int i=0;i<strlen(ch);i++)
        {
            passwd_int[i] = (int) *(ch+i);
        }
        // shift bits
        for(int i=0;i< strlen(ch);i++)
        {
            int tmp = passwd_int[i] ^ SALT;
            *(passwd_crypted+i) = tmp;
        }
    } else {
        fprintf(stderr,"%s","Error allocating memory");
    }
}