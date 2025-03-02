class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> res;
            int n1 = nums1.size(), n2 = nums2.size();
            int i = 0, j = 0;
            while (i < n1 && j < n2) {
                const int& id1 = nums1[i][0], id2 = nums2[j][0];
                const int& v1 = nums1[i][1], v2 = nums2[j][1];
                if (id1 == id2) {
                    res.push_back({id1, v1+v2});
                    i++, j++;
                } else if (id1 < id2) {
                    res.push_back({id1, v1});
                    i++;
                } else {
                    res.push_back({id2, v2});
                    j++;
                }
            }
            while (i < n1) {
                res.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            while (j < n2) {
                res.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
            return res;
        }
    };