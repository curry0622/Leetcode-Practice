class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.size();

        for(int i = 0; i < n;) {
            int num = 1;
            for(int j = 1; i + j < n; j++) {
                if(colors[i] == colors[i + j])
                    num++;
                else
                    break;
            }
            if(num > 1) {
                cost += getCost(neededTime, i, num);
                i += num;
            } else
                i++;
        }

        return cost;
    }

    int getCost(const vector<int>& time, int start, int num) {
        int sum = time[start];
        int max = time[start];
        for(int i = 1; i < num; i++) {
            sum += time[start + i];
            if(max < time[start + i])
                max = time[start + i];
        }
        return sum - max;
    }
};