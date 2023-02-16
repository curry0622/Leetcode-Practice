class Solution {
public:
    int countOdds(int low, int high) {
        return (high+1)/2 - low/2;
    }
};

// How many odds are there in [low, high]?
// ans: odd of [0, high] - odd of [0, low-1]