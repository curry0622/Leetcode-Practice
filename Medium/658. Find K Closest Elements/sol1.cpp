class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<int> findx = binarySearch(arr, x);
        if(findx.at(0) == 1) {
            // x is found in arr
            ans = bidirectionFind(arr, k, x, findx.at(1), true);
        } else {
            // x isn't in arr
            ans = bidirectionFind(arr, k, x, findx.at(1), false);
        }
        return ans;
    }

    vector<int> binarySearch(vector<int> arr, int x) {
        vector<int> ans;
        int left = 0, right = arr.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr.at(mid) == x) {
                ans.push_back(1);
                ans.push_back(mid);
                return ans;
            } else if(x < arr.at(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        ans.push_back(0);
        ans.push_back(left);
        return ans;
    };

    vector<int> bidirectionFind(vector<int> arr, int k, int x, int idx, bool xInArr) {
        vector<int> ans;
        int i, j;
        if(xInArr) {
            i = idx - 1;
            j = idx + 1;
            ans.push_back(x);
        } else {
            i = idx - 1;
            j = idx;
        }
        while(ans.size() != k) {
            if(i < 0) {
                ans.push_back(arr.at(j));
                j++;
                continue;
            }
            if(j >= arr.size()) {
                ans.push_back(arr.at(i));
                i--;
                continue;
            }
            if(x - arr.at(i) < arr.at(j) - x) {
                ans.push_back(arr.at(i));
                i--;
            } else if(x - arr.at(i) > arr.at(j) - x) {
                ans.push_back(arr.at(j));
                j++;
            } else {
                if(arr.at(i) < arr.at(j)) {
                    ans.push_back(arr.at(i));
                    i--;
                } else {
                    ans.push_back(arr.at(j));
                    j++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};