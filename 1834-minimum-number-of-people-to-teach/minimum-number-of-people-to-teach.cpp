class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knows(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i + 1].insert(lang);
            }
        }

        unordered_set<int> problemUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) { 
                problemUsers.insert(u);
                problemUsers.insert(v);
            }
        }

        if (problemUsers.empty()) return 0;

        int result = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : problemUsers) {
                if (!knows[user].count(lang)) {
                    count++;
                }
            }
            result = min(result, count);
        }

        return result;
    }
};
