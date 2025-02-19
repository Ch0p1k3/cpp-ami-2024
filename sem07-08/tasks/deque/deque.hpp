#pragma once

#include <cstddef>
#include <initializer_list>

#include <stack/stack.hpp>

class Deque {
public:
    using Value = Stack::Value;

public:
    Deque() = default;
    Deque(const Deque& other);
    Deque(Deque&& other);

    explicit Deque(size_t size);

    Deque(std::initializer_list<Value> list);

    Deque& operator=(const Deque& other) const;
    Deque& operator=(Deque&& other);

    Value operator[](size_t i);

    void Swap(Deque& other);

    void PushBack(Value value);

    void PopBack();

    void PushFront(Value value);

    void PopFront();

    size_t Size() const;

    size_t Empty() const;

    void Clear();

private:
    void MoveHalfToFirst();

    void MoveHalfToSecond();

private:
    Stack first_;
    Stack second_;
};
