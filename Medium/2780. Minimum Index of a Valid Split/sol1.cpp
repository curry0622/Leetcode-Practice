class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int dom, domCnt = 0;
        for (auto num : nums) {
            freq[num]++;
            if (domCnt < freq[num]) {
                dom = num;
                domCnt = freq[num];
            }
        }
        int n = nums.size();
        vector<int> prefixDomCnt(n, 0);
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dom) {
                prefixDomCnt[i]++;
            }
            prefixDomCnt[i] += last;
            last = prefixDomCnt[i];
        }
        for (int i = 0; i < n; i++) {
            if ((prefixDomCnt[i] > (i+1)/2) &&
                ((prefixDomCnt[n-1]-prefixDomCnt[i]) > (n-1-i)/2)) {
                return i;
            }

        }
        return -1;
    }
};

// cnt= i+1
// thrcnt: > cnt/2
// 0,1,2,3,4,5,6
//       ^