#pragma once

#include <cstddef>
#include <initializer_list>

class Deque {
public:
    Deque() = default;
    Deque(const Deque& other) = default;
    Deque(Deque&& other) = default;

    explicit Deque(size_t size);

    Deque(std::initializer_list<int> list);

    Deque& operator=(const Deque& other) = default;
    Deque& operator=(Deque&& other) = default;

    void Swap(Deque& other);

    void PushBack(int value);

    void PopBack();

    void PushFront(int value);

    void PopFront();

    int& operator[](size_t index);

    const int& operator[](size_t index) const;

    size_t Size() const;

    void Clear();

private:
    /* some fields */
};
