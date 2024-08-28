class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> numerators;
        vector<int> denominators;
        int sign = 1;
        if (expression[0] == '-')
            sign = -1;

        int last = 0;
        for (int i = 0 ? sign : 1; i < expression.size(); i++) {
            if (expression[i] == '/') {
                numerators.push_back(stoi(expression.substr(last, i-last)));
                last = i+1;
            }
            if (expression[i] == '+' || expression[i] == '-') {
                denominators.push_back(stoi(expression.substr(last, i-last)));
                last = i;
            }
        }
        denominators.push_back(stoi(expression.substr(last, expression.size()-last)));

        int denominator = findLCM(denominators);
        int numerator = 0;
        for (int i = 0; i < numerators.size(); i++) {
            numerator += numerators[i]*(denominator/denominators[i]);
        }

        string res = "";
        int GCD = gcd(numerator, denominator);
        if (numerator % denominator == 0) {
            res = to_string(numerator/GCD) + "/1";
        } else {
            res = to_string(numerator/GCD) + "/" + to_string(denominator/GCD);
        }
        return res;
    }

    static int lcm(int a, int b) {
        return (a / std::gcd(a, b)) * b;
    }

    int findLCM(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 1, lcm);
    }

    void p(vector<int> v) {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
};