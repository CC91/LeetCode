// 346. Moving Average from Data Stream

class MovingAverage {
private:
    queue<int> q;
    int n;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() <= n) {
            return sum / q.size();
        } else {
            sum -= q.front();
            q.pop();
            return sum / n;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */