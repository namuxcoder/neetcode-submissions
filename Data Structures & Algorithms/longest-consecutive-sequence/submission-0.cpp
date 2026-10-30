class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> hash(nums.begin(), nums.end());

        int longest = 0;
        for (auto x: hash) {
            if (hash.find(x-1) == hash.end()) {
                int length = 1;
                while (hash.find(x+length) != hash.end()) {
                    length++;
                }
                longest = std::max(longest, length);
            }
        }

        return longest;
    }
};
