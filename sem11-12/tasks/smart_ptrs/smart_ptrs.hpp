#pragma once

#include <cstddef>
#include <utility>

template<typename T>
class SharedPtr {
public:
    SharedPtr() = default;

    SharedPtr(const SharedPtr& other) {
        New(other);
    }
    SharedPtr& operator=(const SharedPtr& other) {
        Reset();
        New(other);
        return *this;
    }

    SharedPtr(SharedPtr&& other) {
        Swap(std::move(other));
    }
    SharedPtr& operator=(SharedPtr&& other) {
        Reset();
        Swap(std::move(other));
        return *this;
    }

    const T* Get() const {
        return ptr_;
    }

    T& operator*() {
        return *ptr_;
    }

    const T& operator*() const {
        return *ptr_;
    }

    T* operator->() {
        return ptr_;
    }

    const T* operator->() const {
        return ptr_;
    }

    ~SharedPtr() {
        Reset();
    }
public:
    template<typename Q, typename... TArgs>
    friend SharedPtr<Q> MakeShared(TArgs... args);

private:
    void New(const SharedPtr& s) {
        ptr_ = s.ptr_;
        cnt_ = s.cnt_;
        if (cnt_) {
            ++*cnt_;
        }
    }

    void Swap(SharedPtr&& s) {
        std::swap(ptr_, s.ptr_);
        std::swap(cnt_, s.cnt_);
    }

    void Reset() {
        if (!cnt_) {
            return;
        }
        if (--*cnt_) {
            return;
        }
        delete ptr_;
        delete cnt_;
        ptr_ = nullptr;
        cnt_ = nullptr;
    }

    SharedPtr(T* ptr): ptr_(ptr), cnt_(new size_t{1}) {
    }

private:
    T* ptr_{nullptr};
    size_t* cnt_{nullptr};
};


template<typename T, typename... TArgs>
SharedPtr<T> MakeShared(TArgs... args) {
    auto* ptr = new T(std::forward<TArgs>(args)...);
    return std::move(SharedPtr<T>(ptr));
}
