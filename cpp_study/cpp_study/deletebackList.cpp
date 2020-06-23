#include "deletebackList.h"
ListNode* DelBackList(ListNode* root, int val) {
    ListNode* head = root;
    if (nullptr == head) {
        return head;
    }
    ListNode* p1 = root;
    ListNode* p2 = root;
    while (val) {
        --val;
        p1 = p1->next;
    }
    while (p1->next != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    ListNode* k = p2->next;
    p2->next = k->next;
    delete k;

}