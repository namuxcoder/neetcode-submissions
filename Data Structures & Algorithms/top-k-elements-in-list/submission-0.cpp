class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> seen;
        for (int x: nums) {
            seen[x]++;
        }

        std::vector<std::pair<int, int>> vec(seen.begin(), seen.end());

        // sort by value descending
        std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back( vec[i].first );
        }

        return result;
    }
};
