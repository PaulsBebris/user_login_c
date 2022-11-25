#include <stdio.h>
#include <stdlib.h>
#include "check_user_exists.h"
#include <string.h>

int check_user_exists()
{
    int user_exists = 0;
    const int SALT = 2561;
    FILE *users_file;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t nread;
    users_file = fopen("../users/users.txt", "rt");
    if (users_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    char exit_user_check = ' ';

    int check_username = 1;
    int check_password = 1;
    int user_authenticated = 1;

    while(exit_user_check != 'Q' && check_username)
    {
        // TODO extract to function
        puts("\nEnter username:");
        char user_name[30];
        gets( &user_name);
        if ((user_name[0] == 'q' || user_name[0] == 'Q') && (strlen(user_name) == 1)) {
            exit_user_check = 'Q';
            break;
        }
        char *line = NULL;
        size_t length;
        ssize_t read;
        // TODO extract to function
        while(read = getline(&line,&length,users_file) != -1)
        {
            if(strlen(&user_name) == strlen(*&line)-1)
            {
                check_username = 0; // stop checking username
                check_password = 1;
            }
        }
        rewind(users_file);
        free(line);
    }
    fclose(users_file);
    // check passsword TODO extract to function
    while(check_password)
    {
        exit_user_check = 'Q'; // to interrupt while loop username check
        FILE * passwd_file = NULL;
        passwd_file = fopen("../users/shadow.txt","rt");
        if (passwd_file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        // TODO extract to function
        puts("\nEnter password:");
        char user_passwd[30];
        gets( &user_passwd);
        char *line = NULL;
        size_t length;
        ssize_t read;
        // TODO extract to function
        while(read = getline(&line,&length,passwd_file) != -1)
        {
            char char_int[4] = {};
            char decrypted_passwd[64] = {};
            // Get string length, because library fubction strlen is not working correctly here! i do not know why ?
            int str_len = 0;
            while(*&line[str_len] != '\n')
            {
                str_len++;
            }
            int bit_possition = 0;
            for(int i=0;i<(str_len/4);i++)
            {
                // fill up array
                int possition = 0;
                for(int j=bit_possition;j<(bit_possition+4);j++)
                {
                    char_int[possition] = *&line[j];
                    possition++;
                }
                // convert array to integer
                int convertable = atoi(&char_int);
                // shift back bits & cast to char
                int tmp_int = convertable ^ SALT;
                decrypted_passwd[i] = (char) tmp_int;
                bit_possition +=4;
            }
            // compare passwd
            if(strlen(&user_passwd) == strlen(&decrypted_passwd))
            {
                if(!strcmp(&decrypted_passwd,&user_passwd))
                {
//                    printf("\n%d", x);
                    check_password--;
                    user_exists++;
                }
            }
        }
        rewind(passwd_file);
        fclose(passwd_file);
        free(line);
    }
    // free pointers

    return user_exists;
}




