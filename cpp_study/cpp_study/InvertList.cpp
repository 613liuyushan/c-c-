#include "ReverseList.h"
#include <stack>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};
ListNode* ReverseList(ListNode* root) {
    if (NULL == root || NULL == root->next) {
        return NULL;
    }
    stack<ListNode*> stk;
    ListNode* p = root;
    for (; p != NULL; p = p->next) {
        stk.push(p);
    }
    ListNode* q = root;
    while (!stk.empty()) {
        q->next = stk.top();
        q = stk.top();
        stk.pop();
    }
    q->next = NULL;
}