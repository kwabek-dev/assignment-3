#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H

#include <deque>
#include <iostream>

template<typename T>
class Queue {
private:
    std::deque<T> data;
public:
    Queue() = default;

    void push(const T& value) { data.push_back(value); }
    void pop() { if (!data.empty()) data.pop_front(); }
    T& front() { return data.front(); }
    const T& front() const { return data.front(); }
    bool empty() const { return data.empty(); }
    std::size_t size() const { return data.size(); }

    // Move the front element to the rear (no-op if empty or single element)
    void move_to_rear() {
        if (data.size() <= 1) return;
        T v = data.front();
        data.pop_front();
        data.push_back(v);
    }

    void clear() { data.clear(); }

    // Display elements to stdout separated by spaces
    void display() const {
        for (const auto& el : data) std::cout << el << " ";
        std::cout << std::endl;
    }
};

#endif // ASSIGNMENT3_QUEUE_H
