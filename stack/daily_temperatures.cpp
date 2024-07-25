class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> istack;

        for (int i = 0; i < n; i++) {
            while (!istack.empty() && temperatures[i] > temperatures[istack.top()]) {
                int index = istack.top();
                istack.pop();
                result[index] = i - index;
            }

            istack.push(i);
        }

        return result;
    }
};