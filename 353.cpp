// 353. Design Snake Game

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width;
        h = height;
        f = food;
        res = 0;
        s.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = s.front();
        auto tail = s.back();
        s.pop_back();
        if (direction == "U") {
            head.first--;
        } else if (direction == "D") {
            head.first++;
        } else if (direction == "L") {
            head.second--;
        } else {
            head.second++;
        }
        
        if (count(s.begin(), s.end(), head) || head.first < 0 || 
        		head.first >= h || head.second < 0 || head.second >= w) {
            return -1;
        }
        
        s.insert(s.begin(), head);
        if (!f.empty() && head == f.front()) {
            f.erase(f.begin());
            s.push_back(tail);
            res++;
        }
        
        return res;
    }
    
private:
    int w;
    int h;
    int res;
    vector<pair<int, int>> f;
    vector<pair<int, int>> s;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */