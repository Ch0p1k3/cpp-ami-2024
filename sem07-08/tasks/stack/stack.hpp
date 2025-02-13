#pragma once

#include <cstdint>

class Stack {
public:
    using Value = uint64_t;

public:
    Stack();

    Stack(const Stack& other);

    Stack& operator=(const Stack& other);

    void Push(Value value);

    Value Top() const;

    Value Pop();

    bool Empty() const;

    std::size_t Size() const;

    ~Stack();

private:
    void Copy(const Stack& s);

    void Free();

private:
    struct Node {
        Value value;
        Node* next;
    };

private:
    Node* head_;
    std::size_t size_;
};
