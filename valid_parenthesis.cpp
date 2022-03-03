class Solution {
public:
    bool isValid(string s) {
        stack<char> schar;
        
        for (char &c : s)
        {
            switch (c)
            {
                case '(': schar.push(c); break;
                case '[': schar.push(c); break;
                case '{': schar.push(c); break;
                case ')':
                    if (schar.empty() || schar.top() != '(')
                    {
                        return false;
                    }
                    else
                    {
                        schar.pop();
                        break;
                    }
                case ']':
                    if (schar.empty() || schar.top() != '[')
                    {
                        return false;
                    }
                    else
                    {
                        schar.pop();
                        break;
                    }
                case '}':
                    if (schar.empty() || schar.top() != '{')
                    {
                        return false;
                    }
                    else
                    {
                        schar.pop();
                        break;
                    }
            }
        }
        
        return schar.empty();
    }
};
