#include "InsertionSort.h"

void InsertionSort(std::vector<int>& v) {
	if (v.size() == 0 || v.size() == 1)
		return;
	int k;
	for (int i = 1; i < v.size(); ++i) {
		k = i;
		while (v[k] < v[k - 1]) {
			std::swap(v[k], v[k - 1]);
			--k;
			if (k == 0)
				break;
		}
	}
}