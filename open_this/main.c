#include <stdio.h>
#include <stdlib.h>
void parse_optional_argument(char* argument,int *return_adr){
    *return_adr = 1;
    // il do that later
}
int main(int argc,char** argv) {
    int argument = 0; //arg dictionary at installer/args
    int *parsed_arg = &argument;
    if (argc == 1) {
        printf("needs 1 argument[s] \n"
        "   %s [repo_name] [-h]\n"
        ,
        argv[0]
    );
}
    if (argc == 3) {
        parse_optional_argument(argv[2],parsed_arg);
    }
    printf("%d\n",*parsed_arg);
    return 0;
    }