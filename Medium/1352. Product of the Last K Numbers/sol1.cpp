class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            fill(nums.begin(), nums.end(), 0);
        }
        if (nums.size() > 0 && nums.back() != 0) {
            num *= nums.back();
        }
        nums.push_back(num);
    }

    int getProduct(int k) {
        int n = nums.size();
        if (n == k) {
            if (n > 1 && nums[0] == 0)
                return 0;
            return nums.back();
        }
        int a = nums[n - 1 - k];
        int b = nums[n - 1 - k + 1];
        int c = nums[n - 1];
        if (a == 0) {
            if (b == 0)
                return 0;
            return c;
        }
        return c / a;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */