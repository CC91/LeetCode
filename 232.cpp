// 232. Implement Queue using Stacks

class Queue {
private:
    stack<int> inStk;
    stack<int> outStk;
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        inStk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (outStk.empty()) {
            while (!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        outStk.pop();
    }

    // Get the front element.
    int peek(void) {
        if (outStk.empty()) {
            while (!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        return outStk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return inStk.empty() && outStk.empty();
    }
};