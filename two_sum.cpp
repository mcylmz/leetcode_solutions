class Solution
{
public:
    unordered_map<int, int> um;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> indices;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int d = target - nums.at(i);
            
            if (um.find(d) != um.end())
            {
                indices.push_back(um[d]);
                indices.push_back(i);
            }
            else
            {
                um.insert({nums.at(i), i});
            }
        }
        
        return indices;
    }
};
