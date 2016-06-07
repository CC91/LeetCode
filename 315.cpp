// 315. Count of Smaller Numbers After Self

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> sorted;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int left = 0;
            int right = sorted.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sorted[mid] >= nums[i]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = right;
            sorted.insert(sorted.begin() + right, nums[i]);
        }
        return res;
    }
};



class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> sorted;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int d = distance(sorted.begin(), lower_bound(sorted.begin(), sorted.end(), nums[i]));
            res[i] = d;
            sorted.insert(sorted.begin() + d, nums[i]);
        }
        return res;
    }
};



class Solution {
public: // binary search tree
    struct Node {
       int smallNode;
       int val;
       Node *left;
       Node *right;
       Node(int v, int s) : val(v), smallNode(s), left(NULL), right(NULL) {}
    };
    
    int insert(Node* &root, int v) {
        if (!root) {
            root = new Node(v, 0);
            return 0;
        }
        if (root -> val > v) {
            root -> smallNode++;
            return insert(root -> left, v);
        }
        else {
            return insert(root -> right, v) + root -> smallNode + (root -> val < v ? 1 : 0);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};



