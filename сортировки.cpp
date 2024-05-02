#include <iostream>
#include <vector>
#include <chrono> 
#include "qsort.h"
#include "RadixSort_LSD.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "Shellsort_Hibbard.h"



class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

int main() {
	Timer t;
	std::vector<int> v, v1;
	std::srand(time(0));
	int u = 100000000;
	for (int i = 0; i < u; ++i)
		v.push_back(std::rand());
	//v1 = v;
	int* mas = new int[u];
	for (int i = 0; i < u; ++i)
		mas[i] = v[i];
	t.reset();
	radixsort(mas,mas+u);
	std::cout << t.elapsed() << '\n';
	t.reset();
	qsort(v,0,u-1);
	std::cout << t.elapsed() << '\n';
//	for (int i = 0; i < u; ++i)
	//	std::cout << v[i] << '\n';
	return 0;
}

