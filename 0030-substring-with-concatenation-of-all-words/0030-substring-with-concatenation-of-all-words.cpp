class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int len = words[0].size();
        int total = len * words.size();

        unordered_map<string, int> need;

        for (string w : words)
            need[w]++;

        for (int start = 0; start < len; start++) {
            int left = start;
            int count = 0;

            unordered_map<string, int> seen;

            for (int right = start; right + len <= s.size(); right += len) {

                string word = s.substr(right, len);

                if (!need.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > need[word]) {
                    string removeWord = s.substr(left, len);
                    seen[removeWord]--;
                    left += len;
                    count--;
                }

                if (count == words.size()) {
                    ans.push_back(left);

                    string removeWord = s.substr(left, len);
                    seen[removeWord]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};