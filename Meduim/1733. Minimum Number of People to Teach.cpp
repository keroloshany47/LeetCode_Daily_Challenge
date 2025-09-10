#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Step 1: represent each user's known languages as a bitset
        vector<bitset<501>> langBit(m);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                langBit[i].set(l);
            }
        }
        
        // Step 2: find blocked friendships
        vector<pair<int,int>> blocked;
        for (auto &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            if ((langBit[u] & langBit[v]).any()) continue; // can already communicate
            blocked.push_back({u, v});
        }
        
        if (blocked.empty()) return 0;
        
        // Step 3: collect all users in blocked friendships
        unordered_set<int> blockedUsers;
        for (auto &p : blocked) {
            blockedUsers.insert(p.first);
            blockedUsers.insert(p.second);
        }
        
        // Step 4: try each language
        int res = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int alreadyKnow = 0;
            for (int user : blockedUsers) {
                if (langBit[user].test(lang)) {
                    alreadyKnow++;
                }
            }
            int needTeach = (int)blockedUsers.size() - alreadyKnow;
            res = min(res, needTeach);
        }
        
        return res;
    }
};
