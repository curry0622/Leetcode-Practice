class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            int res = 0;
            int accSum = 0;
            int numOddAccSum = 0;
            int numEvenAccSum = 0;
            for (int i = 0; i < n; i++) {
                accSum += arr[i];
                if (accSum & 1) {
                    res += numEvenAccSum + 1;
                    numOddAccSum++;
                } else {
                    res += numOddAccSum;
                    numEvenAccSum++;
                }
                res %= 1000000007;
            }
            return res;
        }
    };

    // 1,2,3, 4, 5, 6, 7
    // 1,3,6,10,15,21,28