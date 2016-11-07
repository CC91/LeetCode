// 412. Fizz Buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            res.push_back((i % 3 == 0 && i % 5 == 0) ? 
                "FizzBuzz" : (i % 3 == 0) ? "Fizz" : 
                    (i % 5 == 0) ? "Buzz" : to_string(i));
        }
        return res;
    }
};


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        int i3 = 1;
        int i5 = 1;
        int i15 = 1;
        for (int i = 1; i <= n; i++) {
            if (i == i15 * 15) {
                res.push_back("FizzBuzz");
                i15++;
                i3++;
                i5++;
            } else if (i == i3 * 3) {
                res.push_back("Fizz");
                i3++;
            } else if (i == i5 * 5) {
                res.push_back("Buzz");
                i5++;
            } else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};