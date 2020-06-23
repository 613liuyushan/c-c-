#include "leetcode_20.h"
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (const auto& elem : s) {
            if ('(' == elem || '[' ==elem || '{' ==elem) {
                stk.push(elem);
            }
            else {
                if (stk.size() == 0) {
                    return false;
                }
                if (')' == elem) {
                    if (stk.top() != '(') {
                        return false;
                    }
                }
                if (']' == elem) {
                    if (stk.top() != '[') {
                        return false;
                    }
                }
                if ('}' == elem) {
                    if (stk.top() != '{') {
                        return false;
                    }
                }
                stk.pop();
            }
        }
        if (stk.size() != 0) {
            return false;
        }
        return true;
    }
};