#include "stack.hpp"

namespace {

template<typename T>
T* ReverseList(T* node) {
    T* prev = nullptr;
    while (node) {
        auto* next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

}

Stack::Stack() : head_(nullptr), size_(0) {}

Stack::Stack(const Stack& other) : Stack() {
    Copy(other);
}

Stack& Stack::operator=(const Stack& other) {
    Free();
    Copy(other);
    return *this;
}

Stack::Value Stack::operator[](std::size_t i) {
    auto* node = head_;
    while (i-- != 0) {
        node = node->next;
    }
    return node->value;
}

void Stack::Push(Value value) {
    head_ = new Node{value, head_};
    ++size_;
}

Stack::Value Stack::Top() const {
    return head_->value;
}

Stack::Value Stack::Pop() {
    auto* old_head = head_;
    auto old_value = old_head->value;
    head_ = head_->next;
    delete old_head;
    --size_;
    return old_value;
}

bool Stack::Empty() const {
    return Size() == 0;
}

std::size_t Stack::Size() const {
    return size_;
}

Stack::~Stack() {
    Free();
}

void Stack::Copy(const Stack& other) {
    auto* head = other.head_;
    while (head != nullptr) {
        Push(head->value);
        head = head->next;
    }
    head_ = ReverseList(head_);
}

void Stack::Free() {
    while (!Empty()) {
        Pop();
    }
}
