// 295. Find Median from Data Stream

class MedianFinder {
private:
    priority_queue<int> small, large;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size()<large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size()>large.size()?small.top():0.5*(small.top()-large.top());
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


class MedianFinder {
private:
    multiset<int> small, large;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        large.insert(num);
        small.insert(-*large.begin());
        large.erase(large.begin());
        if (small.size()>large.size()) {
            large.insert(-*small.begin());
            small.erase(small.begin());
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return large.size()>small.size()?*large.begin():0.5*(*large.begin()-*small.begin());
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();