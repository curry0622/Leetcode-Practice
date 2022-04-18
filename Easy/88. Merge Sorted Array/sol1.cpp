

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int ans[m + n];
    int a = 0, b = 0, endIdx = 0;
    for(int i = 0; i < m + n; i++) {
        if(a >= m || b >= n) {
            endIdx = i;
            break;
        }
        if(nums1[a] < nums2[b]) {
            ans[i] = nums1[a++];
        } else {
            ans[i] = nums2[b++];
        }
    }
    if(a < m) {
        for(; a < m; a++) {
            ans[endIdx++] = nums1[a];
        } 
    }
    if(b < n) {
        for(; b < n; b++) {
            ans[endIdx++] = nums2[b];
        }
    }
    for(int i = 0; i < m + n; i++) {
        nums1[i] = ans[i];
    }
}