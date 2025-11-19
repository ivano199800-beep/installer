#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void end(int system_exit_value) {
    printf();
    exit(system_exit_value);
}
void parse_optional_argument(char* argument, int *return_adr){
    if (strcmp(argument, "0") == 0) {
        *return_adr = 0;
    } else if (strcmp(argument, "-e") == 0) {
        *return_adr = 1;  // exec init.sh
    } else if (strcmp(argument, "-v") == 0) {
        *return_adr = 2;  // version
    } else if (strcmp(argument, "v") == 0) {
        *return_adr = 3;  // print help.txt
    } else {
        *return_adr = -1; // unknown flag
    }
}
int main(int argc,char** argv) {
    int argument = 0; //arg dictionary at installer/args
    int *parsed_arg = &argument;
    
    if (argc == 1) {
        printf("needs 1 argument[s] \n"
        "   %s [repo_name] [OPTIONAL_FLAG]\n"
        ,
        argv[0]
        );
        printf("argument 2 is EMPTY\n");
        end(1);
    }
    
    char *repo_name = argv[1];
    
    if (argc == 2) {
        printf("no optional arguments\n");
        end(0);
    }
    
    if (argc >= 3) {
        parse_optional_argument(argv[2], parsed_arg);
        printf("parsed arg return value: %d\n", *parsed_arg);
        
        // Handle flag 3: print help.txt from the repo
        if (*parsed_arg == 3) {
            char help_path[256];
            snprintf(help_path, sizeof(help_path), "%s/help.txt", repo_name);
            FILE *help_file = fopen(help_path, "r");
            if (help_file == NULL) {
                printf("Error: Could not open %s\n", help_path);
                return 1;
            }
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), help_file) != NULL) {
                printf("%s", buffer);
            }
            fclose(help_file);
        }
    }

    end(0);
    }