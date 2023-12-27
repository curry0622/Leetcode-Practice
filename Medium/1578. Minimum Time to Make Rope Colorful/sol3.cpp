class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int len = colors.length();
        int left = 0, right = 1;
        int sumTime = neededTime[left];
        int maxTime = neededTime[left];
        char currColor = colors[left];
        while (right < len) {
            sumTime += neededTime[right];
            if (colors[right] == currColor) {
                maxTime = max(maxTime, neededTime[right]);
            } else {
                sumTime -= maxTime;
                left = right;
                currColor = colors[left];
                maxTime = neededTime[left];
            }
            right++;
        }
        return sumTime - maxTime;
    }
};