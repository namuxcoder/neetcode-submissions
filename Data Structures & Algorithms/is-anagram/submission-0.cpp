class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> smap;
        std::unordered_map<char, int> tmap;
        for (int i = 0; i < s.size(); i++) {
            smap[ s[i] ]++;
            tmap[ t[i] ]++;
        }

        return smap == tmap;
    }
};
