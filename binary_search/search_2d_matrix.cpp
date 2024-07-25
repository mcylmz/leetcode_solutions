class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            int middle_element = matrix[middle / cols][middle % cols];

            if (middle_element == target)
                return true;
            else if (middle_element < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return false;
    }
};