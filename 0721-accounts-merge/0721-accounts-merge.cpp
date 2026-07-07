#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;

        // Build graph
        for (auto &account : accounts) {
            string name = account[0];

            for (int i = 1; i < account.size(); i++) {
                emailToName[account[i]] = name;

                if (i == 1) continue;

                graph[account[i]].push_back(account[i - 1]);
                graph[account[i - 1]].push_back(account[i]);
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> ans;

        for (auto &it : emailToName) {
            string email = it.first;

            if (visited.count(email))
                continue;

            vector<string> component;
            stack<string> st;
            st.push(email);
            visited.insert(email);

            while (!st.empty()) {
                string cur = st.top();
                st.pop();

                component.push_back(cur);

                for (auto &nei : graph[cur]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        st.push(nei);
                    }
                }
            }

            sort(component.begin(), component.end());
            component.insert(component.begin(), emailToName[email]);

            ans.push_back(component);
        }

        return ans;
    }
};
