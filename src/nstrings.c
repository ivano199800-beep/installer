#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "headers/NSTRING.h"

// Function to append a C string to an existing string struct
string string_app_cstr(char* cstr, string *dest) {
    int y = 0;
    // Find the current length of the destination string
    int dstlen = dest->len;

    // Resize the content buffer to fit the new string plus the null terminator
    dest->content = realloc(dest->content, dstlen + strlen(cstr) + 1);
    if (!dest->content) {
        printf("Memory allocation failed!\n");
        return *dest;
    }

    // Copy the content of cstr into the destination
    while (cstr[y] != '\0') {
        dest->content[dstlen + y] = cstr[y];
        y++;
    }

    // Null-terminate the string
    dest->content[dstlen + y] = '\0';

    // Update the length of the destination string
    dest->len += strlen(cstr);
    dest->times_modified++;

    return *dest;
}

// Function to create a new string struct from a C string
string new_string(char *cstr) {
    string ret;
    ret.len = strlen(cstr);  // Calculate the length of the string
    ret.content = malloc(ret.len + 1);  // Allocate memory for the content
    if (!ret.content) {
        printf("Memory allocation failed!\n");
        ret.len = 0;
        ret.times_modified = -1;
        return ret;
    }
    strcpy(ret.content, cstr);  // Copy the C string into the struct
    ret.times_modified = 0;  // Initialize modification count
    return ret;
}

// Function to concatenate two strings (destination string and source string)
string string_cat(string* destination, string source) {
    int new_len = destination->len + source.len;  // Calculate the new total length
    char* tmp = realloc(destination->content, new_len + 1);  // Allocate memory for the concatenated string
    if (!tmp) {
        printf("FAILED TO REALLOCATE\n");
        return new_string("none");
    }

    // Update destination's content pointer and length
    destination->content = tmp;
    destination->len = new_len;

    // Copy the source string into the destination at the correct position
    strcpy(destination->content + destination->len - source.len, source.content);

    destination->times_modified++;  // Increment modification count
    return *destination;
}
