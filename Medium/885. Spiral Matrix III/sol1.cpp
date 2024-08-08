enum class Dir {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int cnt = rows * cols;
        int currR = rStart, currC = cStart;
        Dir d = Dir::RIGHT;
        int currStep = 0;
        int maxStep = 1;
        int stepCnt = 0;

        while (cnt > 0) {
            if (isValid({currR, currC}, rows, cols)) {
                res.push_back({currR, currC});
                cnt--;
            }
            if (currStep == maxStep) {
                d = changeDir(d);
                currStep = 1;
                stepCnt++;
                printD(d);
            } else {
                currStep++;
            }
            if (stepCnt == 2) {
                stepCnt = 0;
                maxStep++;
            }
            update(currR, currC, d);
        }

        return res;
    }

    bool isValid(vector<int> p, int rows, int cols) {
        int r = p[0], c = p[1];
        if (r < 0 || r >= rows)
            return false;
        if (c < 0 || c >= cols)
            return false;
        return true;
    }

    Dir changeDir(Dir d) {
        if (d == Dir::RIGHT)
            return Dir::DOWN;
        if (d == Dir::DOWN)
            return Dir::LEFT;
        if (d == Dir::LEFT)
            return Dir::UP;
        if (d == Dir::UP)
            return Dir::RIGHT;
        return d;
    }

    void printD(Dir d) {
        if (d == Dir::RIGHT)
            cout << "RIGHT" << endl;
        if (d == Dir::DOWN)
            cout << "DOWN" << endl;
        if (d == Dir::LEFT)
            cout << "LEFT" << endl;
        if (d == Dir::UP)
            cout << "UP" << endl;
    }

    void update(int& currR, int& currC, Dir d) {
        if (d == Dir::RIGHT)
            currC++;
        if (d == Dir::DOWN)
            currR++;
        if (d == Dir::LEFT)
            currC--;
        if (d == Dir::UP)
            currR--;
    }
};

