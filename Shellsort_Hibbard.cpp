#include "Shellsort_Hibbard.h"

void shellsorthib(int* l, int* r) {
	int sz = r - l;
	if (sz <= 1) return;
	int step = 1;
	while (step < sz) step <<= 1;
	step >>= 1;
	if (step != 1)
		step--;
	while (step >= 1) {
		for (int* i = l + step; i < r; i++) {
			int* j = i;
			int* diff = j - step;
			while (diff >= l && *diff > * j) {
				std::swap(*diff, *j);
				j = diff;
				diff = j - step;
			}
		}
		step /= 2;	
	}
}