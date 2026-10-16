class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> counts;
        for (int x: nums) { 
            counts[x]++; 
        };

        // create vector based on counts
        std::vector<vector<int>> buckets( nums.size() + 1);
        for ( auto &[val, cnt]: counts ) {
            buckets[cnt].push_back(val);
        }

        std::vector<int> result;
        result.reserve(k);
        // loop through buckets from max size down
        for (int c = nums.size(); c > 0; c--) {
            // see if that freq has data?
            for (int v: buckets[c]) {
                result.push_back( v );
                if (result.size() == k) return result;
            }
        }
    }
};
