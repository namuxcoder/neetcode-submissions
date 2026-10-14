class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> groups;

        for (const auto &x: strs) {
            string word = x;
            std::sort(word.begin(), word.end());
            groups[word].push_back( x );
        }

        vector<vector<string>> result;
        for (auto &entry: groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
