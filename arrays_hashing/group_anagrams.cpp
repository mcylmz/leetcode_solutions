// sort solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagrams[sorted_str].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& p : anagrams) {
            result.push_back(p.second);
        }

        return result;
    }
};

