class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        int max_freq = 0;
        for (auto& pair : freq_map) {
            max_freq = std::max(max_freq, pair.second);
        }

        vector<vector<int>> buckets(max_freq + 1);

        for (auto& pair : freq_map) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for (int i = max_freq; i >= 1 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};