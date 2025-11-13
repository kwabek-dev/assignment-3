#ifndef ASSIGNMENT3_SEARCHSORT_H
#define ASSIGNMENT3_SEARCHSORT_H

#include <vector>
#include "Queue.h"

// Sort the queue using insertion sort (template must be visible to TU)
template<typename T>
void insertion_sort_queue(Queue<T>& q, bool descending = false) {
    std::vector<T> v;
    while (!q.empty()) { v.push_back(q.front()); q.pop(); }

    for (std::size_t i = 1; i < v.size(); ++i) {
        T key = v[i];
        std::size_t j = i;
        if (!descending) {
            while (j > 0 && v[j - 1] > key) { v[j] = v[j - 1]; --j; }
        } else {
            while (j > 0 && v[j - 1] < key) { v[j] = v[j - 1]; --j; }
        }
        v[j] = key;
    }

    for (const auto& el : v) q.push(el);
}

// Recursive linear search returning last occurrence index, starting at `index`.
// Returns -1 if not found.
inline int linear_search_last(const std::vector<int>& arr, int target, int index) {
    if (index >= static_cast<int>(arr.size())) return -1;
    int res = linear_search_last(arr, target, index + 1);
    if (res != -1) return res;
    return (arr[index] == target) ? index : -1;
}

#endif // ASSIGNMENT3_SEARCHSORT_H
