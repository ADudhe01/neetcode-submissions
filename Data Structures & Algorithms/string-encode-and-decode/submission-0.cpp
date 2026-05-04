class Solution {
public:

    string encode(vector<string>& strs) {
        // approach (length + "#" + strs[i])
        string encoded_str = "";
        for (string s: strs) {
            encoded_str += to_string(s.size()) + "#" + s;
        }

        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;

        int i = 0;
        while (i < s.size()) {
            int len, j = i;
            while (s[j] != '#') {
                j++;
            }

            len = stoi(s.substr(i, j));
            decoded_strs.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }

        return decoded_strs;
    }
};
