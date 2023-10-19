class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stkS, stkT;
        for (char c : s) {
            if (c == '#' && stkS.empty())
                continue;
            if (c == '#')
                stkS.pop();
            else
                stkS.push(c);
        }
        for (char c : t) {
            if (c == '#' && stkT.empty())
                continue;
            if (c == '#')
                stkT.pop();
            else
                stkT.push(c);
        }
        // printStk(stkS);
        // printStk(stkT);
        while(!stkS.empty() && !stkT.empty()) {
            char ss = stkS.top();
            char tt = stkT.top();
            stkS.pop();
            stkT.pop();
            if (ss != tt)
                return false;
        }
        if (!stkS.empty() || !stkT.empty())
            return false;
        return true;
    }

    void printStk(stack<char> stk) {
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }
};