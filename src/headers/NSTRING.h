#ifndef STRINGS_H
#define STRINGS_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    char* content;
    int len;
    int times_modified;
} string;

string string_app_cstr(char* cstr, string *dest);
string new_string(char *cstr);
string string_cat(string* destination, string source);
#endif