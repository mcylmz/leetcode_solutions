class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> istack;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int result;
                int op2 = istack.top(); istack.pop();
                int op1 = istack.top(); istack.pop();

                if (token == "+")
                    result = op1 + op2;
                else if (token == "-")
                    result = op1 - op2;
                else if (token == "*")
                    result = op1 * op2;
                else
                    result = op1 / op2;

                istack.push(result);
            }
            else {
                istack.push(stoi(token));
            }

        }

        return istack.top();
    }
};