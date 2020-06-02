#include <stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
				stk.push(s[i]);
			}
			else {
				if (stk.size() == 0) {
					return false;
				}
				if (s[i] == '}') {
					if (stk.top() != '{') {
						return false;
					}
				}
				if (s[i] == ']') {
					if (stk.top() != '[') {
						return false;
					}
				}
				if (s[i] == ')') {
					if (stk.top() != '(') {
						return false;
					}
				}
				stk.pop();
			}

		}
		if (stk.size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};