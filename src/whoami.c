#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>

int main(int argc, char** argv){
    
    //get real id of the user
    uid_t caller_id = getuid();

    // To use with getpwuid
    struct passwd pwd;
    char *buf;
    size_t bufsize;
    int s;
    struct passwd *result;

    bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
        if (bufsize == -1)          
        bufsize = 16384;      

    buf = malloc(bufsize);
    if(buf == NULL){
        perror("malloc");
        return EXIT_FAILURE;
    }

    s = getpwuid_r(caller_id, &pwd, buf, bufsize, &result);


        if (result == NULL){
            errno = s;
            perror("getpwuid_r");
            return EXIT_FAILURE;
        }
    
    puts(pwd.pw_name);
    free(buf);
    return EXIT_SUCCESS;
}

