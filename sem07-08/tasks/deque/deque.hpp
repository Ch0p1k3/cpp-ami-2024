#pragma once

#include <cstddef>
#include <initializer_list>
#include <deque>

class Deque {
public:
    Deque() = default;
    Deque(const Deque& other) = default;
    Deque(Deque&& other) = default;

    explicit Deque(size_t size) : data_(size) {
    }

    Deque(std::initializer_list<int> list) : data_{list} {
    }

    Deque& operator=(const Deque& other) = default;
    Deque& operator=(Deque&& other) = default;

    void Swap(Deque& other) {
        std::swap(data_, other.data_);
    }

    void PushBack(int value) {
        data_.push_back(value);
    }

    void PopBack() {
        data_.pop_back();
    }

    void PushFront(int value) {
        data_.push_front(value);
    }

    void PopFront() {
        data_.pop_front();
    }

    int& operator[](size_t index) {
        return data_[index];
    }

    const int& operator[](size_t index) const {
        return data_[index];
    }

    size_t Size() const {
        return data_.size();
    }

    void Clear() {
        data_.clear();
    }

private:
    std::deque<int> data_;
};
