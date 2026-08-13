class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];

            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            j++;

            string str = s.substr(j, len);

            result.push_back(str);

            i = j + len;
        }

        return result;
    }
};