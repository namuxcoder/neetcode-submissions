class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seen_;
        for (int x: nums) {
            auto result = seen_.insert(x);
            if (!result.second) return true;   
        }

        return false;
    }
};