#include "SelectionSort.h"

void SelectionSort(std::vector<int>& v) {
	if (v.size() == 0 || v.size() == 1)
		return;
	int min;
	for (int i = 0; i < v.size()-1; ++i) {
		min = i;
		for (int j = i + 1; j < v.size(); ++j)
			if (v[min] > v[j])
				min = j;
		std::swap(v[min], v[i]);
	}
}