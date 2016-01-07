class Stack {
// 225. Implement Stack using Queues

private:
    queue<int> q1;
    queue<int> q2;
    
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        if (q1.size()==1) return;
        int tmp = q1.front();
        q1.pop();
        q2.push(tmp);
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
        if (q2.empty()) return;
        for (int i=0; i<q2.size(); i++) {
            q1.push(q2.front());
            q2.pop();
        }
        queue<int> tmp;
        tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};