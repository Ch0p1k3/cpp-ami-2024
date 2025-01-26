#include "list_to_str.hpp"

#include <catch2/catch_test_macros.hpp>

ListNode* Head(int val) {
    return new ListNode{val, nullptr};
}

ListNode* Add(ListNode* tail, int val) {
    auto* next = new ListNode{val, nullptr};
    tail->next = next;
    return next;
}

template <typename U, typename T>
ListNode* ToListNode(U f, const T& arr) {
    ListNode* head = Head(f);
    auto* node = head;
    for (const auto& e : arr) {
        node = Add(node, e);
    }
    return head;
}

void FreeListNode(ListNode* head) {
    while (head) {
        auto* next = head->next;
        delete head;
        head = next;
    }
}

TEST_CASE("Simple") {
    auto* head = ToListNode(1, std::vector<int>{2, 3, 4, 5});
    REQUIRE("1 2 3 4 5" == ListToString(head));
    FreeListNode(head);
}

TEST_CASE("Empty") {
    REQUIRE(ListToString(nullptr).empty());
}
