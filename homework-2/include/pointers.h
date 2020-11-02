#ifndef POINTERS_H
#define POINTERS_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INTERNAL_BUFFER_SIZE 1024

char* Input_External_Storage (char* dest);
char* Input_Internal_Storage ();
char* Input_Dynamic_Storage ();

uint32_t _strlen (const char* str);
char* _strncpy (char* dest, const char* src, size_t n);
char* _strncat (char* dest, const char* src, size_t n);
char* _strstr (const char* text, const char* pattern);
char* _strtok (char* str, const char* delim);

#endif