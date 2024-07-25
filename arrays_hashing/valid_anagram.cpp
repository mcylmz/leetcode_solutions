class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : t) {
            int ct = --count[c - 'a'];
            if (ct < 0)
                return false;
        }

        return true;
    }
};