class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        std::unordered_map<string,int> seen;

        int result_index = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string word = strs[i];
            std::sort(word.begin(), word.end());
            auto it = seen.find(word);
            if (it != seen.end()) {
                result[it->second].push_back( strs[i] );
            }
            else {
                result.push_back( { strs[i] } );
                seen[word] = result_index++;
            }
        }

        return result;
    }
};
