#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <assert.h>
#include <ctype.h>
#include <string.h>

//#define DEBUG

int CompareIgnorePunct (const char* s1, const char* s2);

void Swap (const char** a, const char** b);

int Partition (const char** arr, int left, int right);

void QuickSort (const char** arr, int left, int right);

#endif