#include "deque.hpp"

#include <stdexcept>

namespace {

void MoveHalfToFirst(Stack& f, Stack& s) {
    Stack tmp;
    size_t half_size = (s.Size() + 1) / 2;
    for (size_t i = 0; i < half_size; ++i) {
        tmp.Push(s.Pop());
    }
    while (!tmp.Empty()) {
        f.Push(tmp.Pop());
    }
}

}

Deque::Deque(size_t size) {
    for (size_t i = 0; i < size; ++i) {
        PushBack(Value{});
    }
}

Deque::Deque(std::initializer_list<Value> list) {
    for (const auto& e : list) {
        PushBack(e);
    }
}

size_t Deque::Size() const {
    return first_.Size() + second_.Size();
}

size_t Deque::Empty() const {
    return Size() == 0;
}

void Deque::Clear() {
    while (!Empty()) {
        PopBack();
    }
}

void Deque::PushBack(Value value) {
    second_.Push(value);
}

void Deque::PopBack() {
    if (Empty()) {
        throw std::runtime_error("EMPTY");
    }

    if (second_.Empty()) {
        MoveHalfToSecond();
    }

    second_.Pop();
}

Deque::Value Deque::operator[](size_t i) {
    if (i < first_.Size()) {
        return first_[i];
    }
    return second_[i - first_.Size()];
}

void Deque::PushFront(Value value) {
    first_.Push(value);
}

void Deque::PopFront() {
    if (Empty()) {
        throw std::runtime_error("EMPTY");
    }

    if (first_.Empty()) {
        MoveHalfToFirst();
    }

    first_.Pop();
}


void Deque::MoveHalfToFirst() {
    ::MoveHalfToFirst(first_, second_);
}

void Deque::MoveHalfToSecond() {
    ::MoveHalfToFirst(second_, first_);
}
