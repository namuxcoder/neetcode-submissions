class Solution {
public:

    string encode(vector<string>& strs) {
        string tmp;
        for (auto x: strs) {
            tmp += to_string(x.size()) + "#" + x;
        }

        return tmp;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            string tmp = "";
            // read length first
            while (s[i] != '#') {
                tmp +=  s[i];
                i++;
            }
            // skip hash
            i++;
            int len = stoi(tmp);
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};
