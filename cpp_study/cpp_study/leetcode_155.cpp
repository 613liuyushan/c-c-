#include <stack>
#include<vector>
#include <deque>
#include <algorithm>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    void push(int x) {
        if (vecstack.empty()) {
            vecstack.push(x);
            minstack.push(x);
        }
        else {
            vecstack.push(x);
            if (x < minstack.top()) {
                minstack.push(x);
            }
            else {
                minstack.push(minstack.top());
            }
        }
    }
    void pop() {
        if (vecstack.empty() || minstack.empty()) {
            return;
        }
        vecstack.pop();
        minstack.pop();
    }
    int top() {
        return vecstack.top();
    }
    int getMin() {
        return minstack.top();
    }
private:
    stack<int> minstack;
    stack<int> vecstack;

};

