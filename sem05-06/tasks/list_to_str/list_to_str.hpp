#include <string>

struct ListNode {
    int val;
    ListNode* next;
};

std::string ListToString(ListNode* node) {
    std::string result;
    while (node) {
        result += std::to_string(node->val);
        if (node->next) {
            result += " ";
        }
        node = node->next;
    }
    return result;
}
