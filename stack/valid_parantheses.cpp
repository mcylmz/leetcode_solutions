class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        unordered_map<char, char> matches = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (matches.count(c)) {
                if (cstack.empty() || cstack.top() != matches[c]) {
                    return false;
                }

                cstack.pop();
            }
            else {
                cstack.push(c);
            }
        }

        return cstack.empty();
    }
};