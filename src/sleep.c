#include <stdio.h>
#include <stdlib.h>

void help(void){
    puts("Usage: sleep NUMBER[Options]");
    puts("where number is a float or an integer (in seconds)");
    puts("and options can be s,m,h,d if multiple arguments then they would be summed together");
}

int main(int argc, char** argv){
    if (argc < 2){
        puts("sleep: missing operand");
        help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}



