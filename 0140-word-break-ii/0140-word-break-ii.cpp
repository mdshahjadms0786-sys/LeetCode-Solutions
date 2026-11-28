class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<string> ans;

        function<void(int, string)> solve = [&](int start, string path) {

            if (start == s.size()) {
                ans.push_back(path);
                return;
            }

            for (int end = start; end < s.size(); end++) {

                string word = s.substr(start, end - start + 1);

                if (dict.count(word)) {

                    string newPath = path;

                    if (!newPath.empty())
                        newPath += " ";

                    newPath += word;

                    solve(end + 1, newPath);
                }
            }
        };

        solve(0, "");

        return ans;
    }
};