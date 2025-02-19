#pragma once

#include <string>

class SharedPtr {
public:
    SharedPtr() = default;

    SharedPtr(std::string* ptr)
        : ptr_(ptr)
        , cnt_(new size_t{1}) {
    }

    SharedPtr(const SharedPtr& other) {
        NewPtr(other);
    }
    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other) {
            return *this;
        }
        Reset();
        NewPtr(other);
        return *this;
    }

    const std::string* Get() const {
        return ptr_;
    }

    std::string* Get() {
        return ptr_;
    }

    void Reset(std::string* new_ptr) {
        Reset();
        ptr_ = new_ptr;
        cnt_ = new size_t{1};
    }

    std::string& operator*() {
        return *ptr_;
    }
    const std::string& operator*() const {
        return *ptr_;
    }

    std::string* operator->() {
        return Get();
    }

    const std::string* operator->() const {
        return Get();
    }

    ~SharedPtr() {
        Reset();
    }

private:
    void Reset() {
        if (!ptr_) {
            return;
        }

        if (--(*cnt_) == 0) {
            delete ptr_;
            delete cnt_;
            ptr_ = nullptr;
            cnt_ = nullptr;
        }
    }

    void NewPtr(const SharedPtr& other) {
        ptr_ = other.ptr_;
        cnt_ = other.cnt_;
        if (cnt_) {
            (*cnt_)++;
        }
    }

private:
    size_t* cnt_{nullptr};
    std::string* ptr_{nullptr};
};
