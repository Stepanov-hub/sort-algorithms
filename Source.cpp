#include <vector>

std::vector<int> merge(std::vector<int>& a, std::vector<int>& b) {
    std::size_t n = a.size();
    std::size_t m = b.size();
    int i = 0;
    int j = 0;
    std::vector<int> res(n + m);
    while (i + j < n + m) {
        if (j == m || (i < n && a[i] < b[j])) {
            res[i + j] = a[i];
            i++;
        }
        else {
            res[i + j] = b[j];
            j++;
        }
    }
    return res;
}

std::vector<int> merge_sort(std::vector<int> vec) {
    std::size_t n = vec.size();
    if (n == 1) {
        return vec;
    }

    std::size_t const half_size = n / 2;
    std::vector<int> split_lo(vec.begin(), vec.begin() + half_size);
    std::vector<int> split_hi(vec.begin() + half_size, vec.end());
    split_lo = merge_sort(split_lo);
    split_hi = merge_sort(split_hi);
    return merge(split_lo, split_hi);
}
