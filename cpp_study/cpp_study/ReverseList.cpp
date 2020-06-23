#include "ReverseList.h"
#include <stack>

ListNode* ReverseList(ListNode* root) {
    ListNode* head = root;
    if (NULL == head || NULL == head->next) {
        return head;
    }
    ListNode* pre = head;
    ListNode* cur = head->next;
    while (cur)
    {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = NULL;
    return pre;
}