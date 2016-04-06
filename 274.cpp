// 274. H-Index

class Solution {
public: // http://www.cnblogs.com/grandyang/p/4781203.html
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i=0; i<citations.size(); i++) {
            if (i>=citations[i]) return i;
        }
        return citations.size();
    }
};