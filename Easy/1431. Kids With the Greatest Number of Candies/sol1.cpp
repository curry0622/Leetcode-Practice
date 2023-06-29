class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);
        int most = candies[0];

        for (int i = 1; i < candies.size(); i++) {
            most = max(most, candies[i]);
        }

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= most)
                res[i] = true;
            else
                res[i] = false;
        }

        return res;
    }
};