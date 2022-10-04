class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
        int head;

        for(int i = 0; i < adjacentPairs.size(); i++) {
            for(int num: adjacentPairs[i]) {
                if(mp.find(num) != mp.end()) {
                    mp[num].push_back(i);
                } else {
                    mp[num] = vector<int>{i};
                }
            }
        }

        for(auto i = mp.begin(); i != mp.end(); i++) {
            if((i -> second).size() == 1) {
                head = i -> first;
                break;
            }
        }

        int lastPos = INT_MIN;
        while(ans.size() != adjacentPairs.size() + 1) {
            ans.push_back(head);
            for(int pos: mp[head]) {
                if(pos != lastPos) {
                    lastPos = pos;
                    if(adjacentPairs[pos][0] == head) {
                        head = adjacentPairs[pos][1];
                    } else {
                        head = adjacentPairs[pos][0];
                    }
                    break;
                }
            }
        }

        return ans;
    }
};