// 165. Compare Version Numbers  

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.size();
        int l2 = version2.size();
        int val1 = 0;
        int val2 = 0;
        int i = 0;
        int j = 0;
        while (i < l1 || j < l2) {
            while (i < l1 && version1[i] != '.') {
                val1 = val1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < l2 && version2[j] != '.') {
                val2 = val2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if (val1 > val2) return 1;
            if (val1 < val2) return -1;
            
            val1 = 0; // if numbers before '.' are equal
            val2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};