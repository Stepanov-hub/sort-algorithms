#include "qsort.h"

void qsort(std::vector<int>& v, int left, int right) {
	if (v.size() == 0 || v.size() == 1)
		return;
	int i = left, j = right, mid = median_3(v[left], v[left + (right - left) / 2], v[right]);
	while (i < j) {
		while (v[i] < mid)
			++i;
		while (v[j] > mid)
			--j;
		if (i <= j) {
			std::swap(v[i], v[j]);
			++i;
			--j;
		}
	}
	if(i<right)
		qsort(v, i, right);
	if(j>left)
		qsort(v, left, j);
}

int median_3(int a, int b, int c) {
	if (a > b)
		if (c > a)
			return a;
		else
			if (c > b)
				return c;
			else
				return b;
	if (c > b)
		return b;
	else
		if (a > c)
			return a;
		else
			return c;
}