class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;

        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (canEatAllBananas(piles, middle, h)) {
                result = middle;
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return result;
    }

private:
    bool canEatAllBananas(const vector<int>& piles, int k, int h) {
        int hours_needed = 0;
        for (int pile : piles) {
            hours_needed += ceil(static_cast<double>(pile) / k);
            if (hours_needed > h) {
                return false;
            }
        }
        
        return hours_needed <= h;
    }
};