class Solution {
public:
    int countOdds(int low, int high) {
        if (!(low & 1) && !(high & 1))
            return (high-low)/2;
        return (high-low)/2+1;
    }
};

// 3(odd)~7(odd)
// 3, 4, 5, 6, 7
// ans: 3

// 3(odd)~6(even)
// 3, 4, 5, 6
// ans: 2

// 4(even)~7(odd)
// 4, 5, 6, 7
// ans: 2

// 4(even)~6(even)
// 4, 5, 6
// ans: 1