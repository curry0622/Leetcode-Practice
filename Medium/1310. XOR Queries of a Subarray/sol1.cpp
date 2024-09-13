class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> prefixes;
        int x = 0;
        for (int n : arr) {
            x ^= n;
            prefixes.push_back(x);
        }
        for (auto q : queries) {
            int l = q[0], r = q[1];
            if (l == 0)
                res.push_back(prefixes[r]);
            else
                res.push_back(prefixes[r] ^ prefixes[l-1]);
        }
        return res;
    }
};

// a,b,c,d,e,f,g
// -,-,c,d,e,-,-

// xor(abcdefg) = xor(ab)^xor(cde)^xor(fg)
// xor(ab)^xor(abcdefg) = xor(ab)^xor(ab)^xor(cde)^xor(fg)
// xor(ab)^xor(abcdefg) = 0^xor(cde)^xor(fg)
// xor(ab)^xor(abcdefg) = xor(cde)^xor(fg)
// xor(fg)^xor(ab)^xor(abcdefg) = xor(cde)
// xor(abcde)^xor(abcdefg)^xor(ab)^xor(abcdefg) = xor(cde)
// xor(abcde)^xor(ab) = xor(cde)

// xor(abcdefg) = xor(abcde)^xor(fg)
// xor(abcde)^xor(abcdefg) = xor(abcde)^xor(abcde)^xor(fg)
// xor(abcde)^xor(abcdefg) = 0^xor(fg)
// xor(abcde)^xor(abcdefg) = xor(fg)