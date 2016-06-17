// 281. Zigzag Iterator

class ZigzagIterator {
private:
    vector<vector<int>> v;
    int i;
    int j;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        v.push_back(v2);
        i = 0;
        j = 0;
    }

    int next() {
        return i <= j ? v[0][i++] : v[1][j++];
    }

    bool hasNext() {
        if (i >= v[0].size()) {
            i = INT_MAX;
        }
        if (j >= v[1].size()) {
            j = INT_MAX;
        }
        return i < v[0].size() || j < v[1].size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */



 class ZigzagIterator {
private:
    vector<int> v;
    int i = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int n = max(n1, n2);
        for (int j = 0; j < n; j++) {
            if (j < n1) {
                v.push_back(v1[j]);
            }
            if (j < n2) {
                v.push_back(v2[j]);
            }
        }
    }

    int next() {
        return v[i++];
    }

    bool hasNext() {
        return i < v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


 class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            q.push({v1.begin(), v1.end()});
        }
        if (!v2.empty()) {
            q.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        auto head = q.front().first;
        auto tail = q.front().second;
        q.pop();
        if (head + 1 != tail) {
            q.push({head + 1, tail});
        }
        return *head;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */