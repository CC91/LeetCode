// 167. Two Sum II - Input array is sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            if (m.count(target - numbers[i])) {
                return {m[target - numbers[i]], i + 1};
            } else {
                m[numbers[i]] = i + 1;
            }
        }
        return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int t = target - numbers[i];
            int left = i + 1;
            int right = numbers.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < t) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int t = numbers[i] + numbers[j];
            if (t == target) {
                return {i + 1, j + 1};
            } else if (t < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};