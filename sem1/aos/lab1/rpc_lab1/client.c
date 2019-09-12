#include "square.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    CLIENT* cl;
    square_in in;
    square_out* out;
    if(argc != 3){
        printf("client <localhost> <integer>");
        exit(1);
    }

    cl = clnt_create (argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");
    in.arg1 = atol (argv [2]);
    if ((out = squareproc_1(&in, cl)) == NULL){
        printf ("Error"); 
        exit(1);
    }
    printf ("Result %ld\n", out -> res1);
    exit(0);
    return 0;
}