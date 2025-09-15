#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

void help(void){
    fprintf(stderr,"Usage: sleep DURATION\n");
    fprintf(stderr,"where duration is an integer (in seconds)\n");
}

int main(int argc, char** argv){
    if (argc != 2){
        fprintf(stderr,"sleep: missing operand");
        help();
        return EXIT_FAILURE;
    }

    char *endptr;
    errno = 0;
    long time = strtol(argv[1], &endptr, 10);

    if (errno != 0 || *endptr != '\0' || time < 0 || time > INT_MAX) {
        fprintf(stderr, "sleep: invalid time interval '%s'\n", argv[1]);
        help();
        return EXIT_FAILURE;
    }

    sleep((unsigned int)time);

    return EXIT_SUCCESS;
}


