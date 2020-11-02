#include "pointers.h"

char* Input_External_Storage (char* dest) {
	assert (dest != NULL);
	assert (scanf("%s", dest) == 1);

	return dest;
}

char* Input_Internal_Storage () {
	static char buffer[INTERNAL_BUFFER_SIZE];

	assert (scanf ("%s", buffer) == 1);

	return buffer;
}

char* Input_Dynamic_Storage() {
	char* str = NULL;

	assert (scanf ("%ms", &str) == 1);

	return str;
}

uint32_t _strlen (const char* str) {
	assert (str != NULL);

	const char* ptr = str;

	while (*(ptr++));

	return (ptr - 1 - str);
}

char* _strncpy (char* dest, const char* src, size_t n) {
	assert (dest != NULL);
	assert (src != NULL);

	size_t i = 0;
	char* result = dest;

	while (i++ < n && *src) {
		*dest++ = *src++;
	}

	*dest = 0;

	return result;
}

char* _strncat (char* dest, const char* src, size_t n) {
	assert (dest != NULL);
	assert (src != NULL);

	char* result = dest;
	size_t i = 0;

	while (*dest++);
	--dest;

	_strncpy (dest, src, n);

	return result;
}

char* _strstr (const char* text, const char* pattern) {
	assert (text != NULL);
	assert (pattern != NULL);

	const char* pattern_begin = pattern;
	char* ptr_begin = NULL;

	for (const char* ptr = text; *ptr; ++ptr) {
		ptr_begin = ptr;

		while (*ptr && *pattern && *ptr == *pattern) {
			++ptr;
			++pattern;
		}
		
		if (*ptr == *pattern) {
			return ptr_begin;
		}

		ptr = ptr_begin;
		pattern = pattern_begin;
	}

	return NULL;
}

char* _strtok (char* str, const char* delim) {
	static char* position = NULL;

	if (str != NULL) {
		position = str;
	}

	int non_delimiter = 0;

	while (*position) {
		non_delimiter = 1;

		for (const char* ptr = delim; *ptr; ++ptr) {
			if (*position == *ptr) {
				non_delimiter = 0;
				break;
			}
		}

		if (non_delimiter) {
			return position;
		}
		
		++position;
	}

	return NULL;
}