class Solution {
public:
    vector<string> findAllRecipes(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies
    ) {
        unordered_map<string, bool> created;
        unordered_map<string, bool> visited;
        unordered_map<string, vector<string>> mapping;
        for (int i = 0; i < recipes.size(); i++) {
            for (auto igd : ingredients[i]) {
                mapping[recipes[i]].push_back(igd);
            }
        }
        for (auto s : supplies) {
            created[s] = true;
            mapping[s] = {s};
        }
        vector<string> res;
        for (auto r : recipes) {
            if (canCreate(r, mapping, created, visited)) {
                res.push_back(r);
            }
        }
        return res;
    }

    bool canCreate(
        const string& r,
        unordered_map<string, vector<string>>& mapping,
        unordered_map<string, bool>& created,
        unordered_map<string, bool>& visited
    ) {
        if (created.find(r) != created.end()) return created[r];
        if (visited[r] && created.find(r) == created.end()) {
            created[r] = false;
            visited[r] = true;
            return false;
        }
        visited[r] = true;
        bool tmp = !mapping[r].empty();
        for (auto igd : mapping[r]) {
            tmp &= canCreate(igd, mapping, created, visited);
        }
        created[r] = tmp;
        return created[r];
    }
};