
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        unordered_set<long long> seen;

        for (int i = 0; i < words.size(); i++)
            mp[words[i]] = i;

        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            int n = w.size();

            for (int j = 0; j <= n; j++) {
                string left = w.substr(0, j);
                string right = w.substr(j);

                if (isPal(left)) {
                    string rev = right;
                    reverse(rev.begin(), rev.end());

                    if (mp.count(rev) && mp[rev] != i) {
                        int a = mp[rev], b = i;
                        long long key = (long long)a * words.size() + b;

                        if (seen.insert(key).second)
                            ans.push_back({a, b});
                    }
                }

                if (j < n && isPal(right)) {
                    string rev = left;
                    reverse(rev.begin(), rev.end());

                    if (mp.count(rev) && mp[rev] != i) {
                        int a = i, b = mp[rev];
                        long long key = (long long)a * words.size() + b;

                        if (seen.insert(key).second)
                            ans.push_back({a, b});
                    }
                }
            }
        }

        return ans;
    }

    bool isPal(const string& s) {
        int l = 0, r = (int)s.size() - 1;

        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }

        return true;
    }
};
