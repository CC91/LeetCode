// 251. Flatten 2D Vector

class Vector2D {
private:
    vector<int> v;
    int i = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto a : vec2d) {
            v.insert(v.end(), a.begin(), a.end());
        }
    }

    int next() {
        return v[i++];
    }

    bool hasNext() {
        return i < v.size();
    }
};


class Vector2D {
private:
    vector<vector<int>> v;
    int x;
    int y;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v = vec2d;
        x = 0;
        y = 0;
    }

    int next() {
        return v[x][y++];
    }

    bool hasNext() {
        while (x < v.size() && y == v[x].size()) {
            x++;
            y = 0;
        }
        return x < v.size();
    }
};


class Vector2D {
private:
    vector<vector<int>>::iterator begin;
    vector<vector<int>>::iterator end;
    int y = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        begin = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        return (*begin)[y++];
    }

    bool hasNext() {
        while (begin != end && y == (*begin).size()) {
            begin++;
            y = 0;
        }
        return begin != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */