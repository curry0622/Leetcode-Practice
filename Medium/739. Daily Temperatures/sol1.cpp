class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);

        for(int i = t.size() - 2; i >= 0; i--) {
            if(t[i] < t[i+1])
                ans[i] = 1;
            else {
                int j = i + 1;
                while(j < t.size()) {
                    if(t[i] >= t[j]) {
                        if(ans[j] == 0) {
                            j = i;
                            break;
                        }
                        j += ans[j];
                    } else {
                        break;
                    }
                }
                if(j >= t.size())
                    ans[i] = 0;
                else
                    ans[i] = j - i;
            }
        }

        return ans;
    }
};
