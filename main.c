#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <gtk-3.0/gtk/gtk.h>
#include "src/createul/createul.h"
#include "src/checkuser/check_user_exists.h"

int main(int argc, char *argv[]) {
    // create user file
    int user_count_given = 0;
    int user_list_created = 0;
    if((argv[1]!=0) && (argv[2]!=0))
    {
        user_count_given = atoi(argv[2]);
        if((strcmp(argv[1],"-u") == 0) && (user_count_given > 1) && (user_count_given < 10))
        {
            // do thread here
            user_list_created = create_user_list(user_count_given);
        } else {
            user_list_created = create_user_list(1);
        }
    } else {
        printf("Please provide arguments for user count in form of: [-u] [count]\n");
    }
    if(user_list_created)
    {
        printf("\nUser list successfully created with %d users.",user_count_given);
    } else {
        fprintf(stderr,"\nERROR createing file");
    }
    // check if user exists
    if(check_user_exists())
    {
        printf("Logged in!");
    }
    return 0;
}
