#include <stdio.h>
#include <stdlib.h>

#include "pointers.h"
#include "quick_sort.h"

char* ReadString(FILE* file, char delim) {
	assert (file != NULL);

	char c = 0;
	char* p = 0;
	char* tmp = 0;
	int curr_len = 0;

	while ((c = fgetc(file)) != EOF && c != delim) {
		tmp = malloc (sizeof (char) * (curr_len + 2));

		strcpy (tmp, p);
		*(tmp + curr_len) = c;
		*(tmp + curr_len + 1) = 0;
		
		free(p);
		p = tmp;

		++curr_len;
	}

	return p;
}

void InitStrings (FILE* file, char** arr, size_t n) {
	assert (file != NULL);
	assert (arr != NULL);

	for (size_t i = 0; i < n; i++) {
		arr[i] = ReadString (file, '\n');
#ifdef DEBUG
		printf("Now I am reading %s", arr[i]);
#endif
	}
}

void FreeStrings (char** arr, size_t n) {
	assert (arr != NULL);
	
	for (size_t i = 0; i < n; i++) {
		free (arr[i]);
	}
}

size_t CountNumberOfLines (FILE* file, char delim) {
	assert (file != NULL);

	size_t lines_num = 0;
	size_t current_offset = ftell (file);

	while (!feof (file)) {
		if (fgetc (file) == delim) {
			++lines_num;
		}
	}
#ifdef DEBUG
	fseek (file, 0, SEEK_SET);
#else
	fseek (file, current_offset, SEEK_SET);
#endif
	return lines_num;
}

char** ReadPoem (FILE* file, size_t* n) {
	assert (file != NULL);

	char** result = NULL;
	size_t lines_num = CountNumberOfLines (file, '\n');

	result = malloc (sizeof (char*) * lines_num);
	
	assert (result != NULL);
	
	InitStrings (file, result, lines_num);

	*n = lines_num;
	
	return result;
}

void FreeMemory (char** arr, size_t n) {
	assert (arr != NULL);
	
	FreeStrings (arr, n);
	free (arr);
}

int WriteToFile (FILE* dest, char** arr, size_t n) {
	assert (dest != NULL);
	assert (arr != NULL);

	for (size_t i = 0; i < n; i++) {
		if (fputs (arr[i], dest) == EOF) {
			return EOF;
		}
		
		if (i + 1 != n) {
			fputc ('\n', dest);
		}
	}

	return 0;
}

int main (int argc, char* argv[]) {
	size_t num_lines = 0;
	char** lines = ReadPoem (fopen ("poem.txt", "r"), &num_lines);
#ifdef DEBUG
	printf("Now there are %d lines\n", num_lines);
#endif
#ifdef DEBUG
	for (size_t i = 0; i < num_lines; i++) {
		printf("%s\n", lines[i]);
	}
#endif
	QuickSort (lines, 0, num_lines - 1);
#ifdef DEBUG
	for (size_t i = 0; i < num_lines; i++) {
		printf("%s\n", lines[i]);
	}
#endif
	WriteToFile (fopen ("result.txt", "w"), lines, num_lines);

	FreeMemory (lines, num_lines);

	return 0;
}