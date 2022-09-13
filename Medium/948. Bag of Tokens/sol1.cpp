class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int i = 0, j = tokens.size() - 1;

        sort(tokens.begin(), tokens.end());
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
            } else if(score > 0 && i != j) {
                power += tokens[j];
                score--;
                j--;
            } else {
                break;
            }
        }

        return score;
    }
};