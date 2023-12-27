class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int, int>> visited;
        int currX = 0, currY = 0;
        visited.push_back({currX, currY});
        for (auto dir : path) {
            switch (dir) {
                case 'N':
                    currY++;
                    break;
                case 'S':
                    currY--;
                    break;
                case 'E':
                    currX++;
                    break;
                case 'W':
                    currX--;
                    break;
            }
            if (find(visited.begin(), visited.end(), make_pair(currX, currY)) != visited.end())
                return true;
            visited.push_back({currX, currY});
        }
        return false;
    }
};