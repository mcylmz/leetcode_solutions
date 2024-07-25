class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return tolower(c);
        });

        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){
            return !isalnum(c);
        }), s.end());

        auto l = s.begin();
        auto r = s.end() - 1;
        while (distance(s.begin(), l) < distance(s.begin(), r)) {
            if (*l != *r) {
                return false;
            }
            else {
                ++l;
                --r;
            }
        }

        return true;
    }
};