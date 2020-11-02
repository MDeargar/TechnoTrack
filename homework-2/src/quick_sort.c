#include "quick_sort.h"

int CompareIgnorePunct (const char* s1, const char* s2) {
	while (*s1 && *s2) {
		if (ispunct(*s1)) {
			++s1;
		} else if (ispunct(*s2)) {
			++s2;
		} else {
			if (*s1 != *s2) {
				return *s1 - *s2;
			}

			++s1;
			++s2;
		}
	}

	return *s1 - *s2;
}

void Swap (const char** a, const char** b) {
	const char* c = *a;
	*a = *b;
	*b = c;
}

int Partition (const char** arr, int left, int right) {
	assert (arr != NULL);
	assert (left >= 0);
	assert (left <= right);

	const char* pivot = arr[right];
	int index = left - 1;

	for (int j = left; j < right; j++) {
		if (CompareIgnorePunct (arr[j], pivot) < 0) {
			++index;
			Swap (&arr[index], &arr[j]);
		}
	}

	Swap (&arr[index + 1], &arr[right]);
	
	return index + 1;
}
/*
void QuickSort (const char** arr, int left, int right) {
	assert (arr != NULL);
	assert (left >= 0 && right >= 0);

	if (left < right) {
		int p_element = Partition (arr, left, right);

		QuickSort (arr, left, p_element - 1);
		QuickSort (arr, p_element + 1, right);
	}
}*/

void QuickSort (const char** arr, int left, int right) {
	assert (arr != NULL);
	assert (left >= 0 && right >= 0);

	int i = left;
	int j = right;
	const char* pivot = arr[(i + j) / 2];

	while (i <= j) {
		while (CompareIgnorePunct(arr[i], pivot) < 0) {
			++i;
		}

		while (CompareIgnorePunct(arr[j], pivot) > 0) {
			--j;
		}

		if (i <= j) {
			Swap (&arr[i], &arr[j]);
			++i;
			--j;
		}
	}

	if (j > left) {
		QuickSort (arr, left, j);
	}

	if (i < right) {
		QuickSort (arr, i, right);
	}
}