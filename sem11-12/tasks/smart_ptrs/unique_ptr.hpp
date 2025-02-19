#include <string>

class UniquePtr {
public:
    UniquePtr() = default;

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) {
        Reset();
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        return *this;
    }

    operator bool() const {
        return ptr_ != nullptr;
    }

    const std::string* Get() const {
        return ptr_;
    }

    std::string* Get() {
        return ptr_;
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

    ~UniquePtr() {
        Reset();
    }

private:
    void Reset() {
        delete ptr_;
    }

private:
    std::string* ptr_{nullptr};
};
