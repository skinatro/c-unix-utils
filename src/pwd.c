#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

//old version with static memory allocation

//#include <string.h>
//#include <linux/limits.h>
// int main(void){
    // char curr_path[PATH_MAX];
    
    //zeroing isnt required?
    // memset(curr_path,0,sizeof curr_path);
    // if (getcwd(curr_path, PATH_MAX) == NULL)
    //     return EXIT_FAILURE;
    // else
    //     puts(curr_path);

    // return EXIT_SUCCESS;
// }

void help(void){
    puts("usage: pwd [-L|-P]");
    puts("-L  print the logical current working directory");
    puts("-P  print the physical current working directory");
}

int main(int argc, char** argv){
    // we ball, i will do dynamic buffer

    int logical = 1; // default: logical
    int opt;
    while ((opt = getopt(argc, argv, "LP")) != -1) {
        switch (opt) {
        case 'L':
            logical = 1;
            break;
        case 'P':
            logical = 0;
            break;
        default:
            fprintf(stderr, "pwd: invalid option\n");
            help();
            return EXIT_FAILURE;
        }
    }

    char *cwd = NULL;
    int to_free = 1;

    if (logical) {
        to_free = 0;
        cwd = getenv("PWD");
        //fall back to physical if unset
        if (cwd == NULL || cwd[0] == '\0') {
            cwd = getcwd(NULL, 0);
            to_free = 1;
        }
    } else {
        cwd = getcwd(NULL, 0);
    }

    if (cwd == NULL) {
        perror("pwd");
        return EXIT_FAILURE;
    }

    puts(cwd);
    if (to_free) free(cwd); 
    return EXIT_SUCCESS;
}

