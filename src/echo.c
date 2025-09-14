#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    int n = 0;
    int start = 1;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        n = 1;
        start = 2;
    }

    if (start < argc) {
        for (int index = start; index < argc; index++) {
            printf("%s", argv[index]);
            if (index + 1 < argc)
                putchar(' ');
        }
    }

    if (!n)
        putchar('\n');

    return EXIT_SUCCESS;
}


//Write tests
// 1. no arguments
// 2. arguments
// 3. no arguments with -n flag
// 4. arguments with -n flag
// 5. invalid arguments with -n flag
// 6. invalid arguments
