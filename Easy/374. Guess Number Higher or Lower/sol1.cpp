/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int low = 1, up = n;
        long long int mid = (low + up) / 2;
        int res = guess(mid);
        while(res != 0) {
            if(res == -1) {
                // too high
                up = mid - 1;
            } else {
                // too low
                low = mid + 1;
            }
            res = guess((low + up) / 2);
            mid = (low + up) / 2;
        }
        return mid;
    }
};