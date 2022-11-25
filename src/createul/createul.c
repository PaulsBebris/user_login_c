#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "createul.h"
#include "../encrtext/encrypttext.h"

int create_user_list(int count) {
    if(count > 10) {
        count = 10;
    }
    // define user list
    char users[][10] = {
            "qw",
            "qwe",
            "qwer",
            "user3",
            "user4",
            "user5",
            "user6",
            "user7",
            "user8",
            "user9",
            "user10"
    };
    FILE * users_fp;
    users_fp = fopen("../users/users.txt","wt");
    if(users_fp != NULL)
    {
        for(int i=0;i<count;i++)
        {
            fputs(users[i],users_fp);
            fputs("\n",users_fp);
        }
        fclose(users_fp);
    } else {
        printf("! users - File open error !");
    }

    // passwords file
    char users_passwd[][64] = {
            "qw",
            "qwe",
            "qwer",
            "qwert",
            "qwerty",
            "user6",
            "user7",
            "user8",
            "user9",
            "user10"
    };

    FILE * fp;
    fp = fopen("../users/shadow.txt","wt");
    if(fp != NULL)
    {
        // entrypt password
        for(int i=0;i<count;i++)
        {
            encrypt_text(&*users_passwd[i]);
            for(int j=0;j < *passwd_size;j++)
            {
                fprintf(fp,"%d",*(passwd_crypted+j));
            }
            fprintf(fp,"\n");
            // Free pointers from other files
            free(passwd_crypted);
            free(passwd_size);
        }
    } else {
        printf("! passwd - File open error !");
    }
    fclose(fp);
    return 1;
};
