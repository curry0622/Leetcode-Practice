class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> score(n, 0);

        for(int i = 0; i < n; i++) {
            if(d[i] == 'L') {
                score[i] = -1;
                int num = 0;
                for(int j = i - 1; j >= 0; j--) {
                    if(d[j] == '.') {
                        num++;
                        score[j]--;
                    } else {
                        if(d[j] == 'R') {
                            num /= 2;
                            for(int k = i - 1; k >= i - num; k--) {
                                score[k]--;
                            }
                        }
                        break;
                    }
                }
            }
            if(d[i] == 'R') {
                score[i] = 1;
                int num = 0;
                for(int j = i + 1; j < n; j++) {
                    if(d[j] == '.') {
                        num++;
                        score[j]++;
                    } else {
                        if(d[j] == 'L') {
                            num /= 2;
                            for(int k = i + 1; k <= i + num; k++) {
                                score[k]++;
                            }
                        }
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(score[i] == 0)
                d[i] = '.';
            if(score[i] == -1)
                d[i] = 'L';
            if(score[i] == 1)
                d[i] = 'R';
        }

        return d;
    }
};