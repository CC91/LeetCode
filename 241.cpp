// 241. Different Ways to Add Parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (ispunct(c)) {
                for (int a : diffWaysToCompute(input.substr(0, i))) {
                    for (int b : diffWaysToCompute(input.substr(i + 1))) {
                        res.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
                    }
                }
            }
        }
        return !res.empty() ? res : vector<int> {stoi(input)};
    }
};