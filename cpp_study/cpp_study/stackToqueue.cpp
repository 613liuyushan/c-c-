#include <stack>
class MyQueue
{
public:
    bool emptyQueue() {
        if (stck1.empty() && stck2.empty()) {
            return true;
        }
        return false;
    }
    void pushQueue(int x) {
        stck1.push(x);
    }
    void popQueue() {
        if (stck2.empty()) {
            if (!stck1.empty()) {
                stck2_botom = stck1.top();
            }
            while (!stck1.empty()) {
                stck2.push(stck1.top());
                stck1.pop();
            }
        }
        stck2.pop();
    }
    int frontQueue() {
        if (!stck2.empty()) {
            return stck2.top();
        }
        else 
            return stck1.top();
    }
    int backQueue() {
        if (!stck1.empty()) {
            return stck1.top();
        }
        else return stck2_botom;
    }

private:
    std::stack<int> stck1;
    std::stack<int> stck2;
    int stck2_botom;

};

