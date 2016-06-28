// 170. Two Sum III - Data structure design

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    m[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto a : m) {
	        int t = value - a.first;
	        if ((m.count(t) && t != a.first) || 
	        	(t == a.first && a.second > 1)) {
	            return true;
	        }
	    }
	    return false;
	}
	
private:
    unordered_map<int, int> m;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);