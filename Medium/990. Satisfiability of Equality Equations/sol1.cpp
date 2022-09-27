class Solution {
public:
    int parent[26];

    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for(string eq: equations) {
            if(eq[1] == '=') {
                parent[find(eq[0] - 'a')] = find(eq[3] - 'a');
            }
        }
        for(string eq: equations) {
            if(eq[1] == '!') {
                if(find(eq[0] - 'a') == find(eq[3] - 'a'))
                    return false;
            }
        }
        return true;
    }

    int find(int x) {
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
};