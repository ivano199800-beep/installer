#include "headers/NSTRING.h"
#include <stdio.h>
int main() { 
    printf("string_test\n");
    string str = new_string("hello world");
    printf("%s\n",str.content);
    free(str.content);
    return 0;
}