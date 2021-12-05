#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, char** argv)
{
    for (int i = argc - 1; i > 0 ; --i) {
        printf("%s ", argv[i]);
    }
    return 0;
}