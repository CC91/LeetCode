// 384. Shuffle an Array

class Solution {
public:
    Solution(vector<int> nums) {
        array = nums;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = original;
        return array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < array.size(); i++) {
            int t = rand() % (array.size() - i);
            swap(array[i], array[i + t]);
        }
        return array;
    }

private:
    vector<int> original;
    vector<int> array;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */