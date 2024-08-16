class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> char_count(26, 0);
        int left = 0;
        int max_count = 0;
        int max_length = 0;

        for (int right = 0; right < s.size(); ++right) {
            char current_char = s[right];
            char_count[current_char - 'A']++;
            max_count = max(max_count, char_count[current_char - 'A']);

            if (right - left + 1 - max_count > k) {
                char_count[s[left] - 'A']--;
                left++;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};