// 271. Encode and Decode Strings

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto &a : strs) {
            res += to_string(a.size()) + '/' + a;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto pos = s.find('/', i);
            int len = stoi(s.substr(i, pos - i));
            res.push_back(s.substr(pos + 1, len));
            i = pos + len + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));