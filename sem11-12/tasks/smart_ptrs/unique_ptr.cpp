#include <iostream>
#include <utility>

template <typename T>
class UniquePtr {
public:
    UniquePtr() = default;

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other) {
        std::swap(ptr_, other.ptr_);
    }
    UniquePtr& operator=(UniquePtr&& other) {
        std::swap(ptr_, other.ptr_);
        return *this;
    }

    operator bool() const {
        return Get() != nullptr;
    }

    const T* Get() const {
        return ptr_;
    }

    T* Get() {
        return ptr_;
    }

    T& operator*() {
        return *Get();
    }

    const T& operator*() const {
        return *Get();
    }

    T* operator->() {
        return Get();
    }

    const T* operator->() const {
        return Get();
    }

    ~UniquePtr() {
        Reset();
    }

public:
    template<typename Q, typename... TArgs>
    friend UniquePtr<Q> MakeUnique(TArgs... args);

private:
    UniquePtr(T* ptr): ptr_(ptr) {
    }

    void Reset() {
        if (ptr_) {
            delete ptr_;
            ptr_ = nullptr;
        }
    }

private:
    T* ptr_{nullptr};
};

template<typename T, typename... TArgs>
UniquePtr<T> MakeUnique(TArgs... args) {
    auto* ptr = new T(std::forward<TArgs>(args)...);
    return std::move(UniquePtr<T>(ptr));
}

// struct Student {
//     std::string Name;
//     std::string Surname;

//     Student(std::string_view name, std::string_view surname)
//         : Name(name)
//         , Surname(surname) {
//     }
// };

int main() {
    auto ptr = MakeUnique<int>(1);
    auto ptr2 = std::move(ptr);
    auto st_ptr = MakeUnique<std::pair<int, int>>(1, 2);
    std::cout << st_ptr->second << std::endl;
    std::cout << *ptr2 << std::endl;
}
