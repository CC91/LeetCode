// 379. Design Phone Directory

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        N = maxNumbers;
        recycle.resize(N);
        flag.resize(N, 1);
        i = 0;
        next = 0;
    }
     
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next == N && i <= 0) {
            return -1;
        }
        if (i > 0) {
            int t = recycle[--i];
            flag[t] = 0;
            return t;
        }
        flag[next] = 0;
        return next++;
    }
     
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 && number < N && flag[number];
    }
     
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < N && !flag[number]) {
            recycle[i++] = number;
            flag[number] = 1;
        }
    }
 
private:
    int N;
    int next;
    int i;
    vector<int> recycle;
    vector<int> flag;
};
 
/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */