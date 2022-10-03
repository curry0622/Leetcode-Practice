class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int cost = 0;
        int sum = neededTime[0], max = neededTime[0], num = 1;

        for(int i = 1; i < n; i++) {
            if(colors[i] == colors[i - 1]) {
                num++;
                sum += neededTime[i];
                if(max < neededTime[i])
                    max = neededTime[i];
            } else {
                if(num > 1)
                    cost += sum - max;
                num = 1;
                sum = neededTime[i];
                max = neededTime[i];
            }
        }

        if(num > 1)
            cost += sum - max;

        return cost;
    }
};