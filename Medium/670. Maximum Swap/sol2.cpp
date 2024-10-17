class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);

        int md = str[str.size()-1];
        int mi = str.size()-1;
        int si = mi;
        int sj = si;
        for (int i = str.size()-2; i >= 0; i--) {
            if (str[i] > md) {
                md = str[i];
                mi = i;
            } else if (str[i] < md) {
                sj = mi;
                si = i;
            }
        }
        swap(str[si], str[sj]);
        return stoi(str);
    }
};