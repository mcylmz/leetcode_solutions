class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower_index = 0;
        int upper_index = nums.size() - 1;

        while (lower_index <= upper_index) {
            int middle_index = lower_index + (upper_index - lower_index) / 2;

            if (nums[middle_index] == target) {
                return middle_index;
            }
            else if (target < nums[middle_index]) {
                upper_index = middle_index - 1;
            }
            else {
                lower_index = middle_index + 1;
            }
        }

        return -1;
    }
};