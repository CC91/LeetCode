// 316. Remove Duplicate Letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {0};
        int visited[26] = {false};
        string res = "";
        for (char c1:s) cnt[c1-'a']++;
        for (char c2:s) {
            cnt[c2-'a']--;
            if (visited[c2-'a']) continue;
            while (!res.empty() && cnt[res.back()-'a']>0 && res.back()>c2) {
                visited[res.back()-'a']=false;
                res.pop_back();
            }
            visited[c2-'a'] = true;
            res.push_back(c2);
        }
        return res;
    }
};