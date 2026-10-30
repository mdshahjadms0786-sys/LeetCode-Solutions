
class Solution {
public:
    vector<string> ans;

    string mp[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, int index, string temp) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : mp[digit]) {
            temp.push_back(ch);

            solve(digits, index + 1, temp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();

        if (digits.empty())
            return ans;

        solve(digits, 0, "");
        return ans;
    }
};
