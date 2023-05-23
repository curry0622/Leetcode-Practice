class KthLargest {
public:
    int k;
    vector<int> nums;
    bool sorted = false;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
    }

    int add(int val) {
        if (!sorted) {
            nums.push_back(val);
            sort(nums.begin(), nums.end());
            sorted = true;
        } else if (val > nums[nums.size() - k]) {
            bool inserted = false;
            for (int i = 1; i < k; i++) {
                if (val <= nums[nums.size() - k + i]) {
                    nums.insert(nums.end() - k + i, val);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                nums.push_back(val);
            }
        }
        return nums[nums.size() - k];
    }

    void printVec() {
        for (int n : nums)
            cout << n << " ";
        cout << endl;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */