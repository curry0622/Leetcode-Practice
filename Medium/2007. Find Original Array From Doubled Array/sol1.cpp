class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;

        if(ans.size() % 2 == 0) {
            int range = 100001;
            vector<int> cnt(range * 2, 0);

            for(int i = 0; i < changed.size(); i++) {
                cnt[changed[i]]++;
            }

            for(int i = 0; i < cnt.size();) {
                if(cnt[i] == 0) {
                    i++;
                } else if(cnt[i] > 0) {
                    if(cnt[2 * i] > 0) {
                        cnt[i]--;
                        cnt[2 * i]--;
                        ans.push_back(i);
                    } else {
                        ans = vector<int>();
                        break;
                    }
                } else {
                    ans = vector<int>();
                    break;
                }
            }
        }

        return ans;
    }
};