class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int trapped_water = 0;

        stack<int> index;
        for (int i = 0; i < n; i++) {
            while (!index.empty() && height[index.top()] < height[i]) {
                int prev_index = index.top();
                index.pop();
                if (!index.empty()) {
                    int h = min(height[i], height[index.top()]) - height[prev_index];
                    trapped_water += h * (i - 1 - index.top());
                }
            }

            index.push(i);
        }

        return trapped_water;
    }
};
