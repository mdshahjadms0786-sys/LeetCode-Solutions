class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;

        for (int x : nums)
            a.push_back(to_string(x));

        sort(a.begin(), a.end(), [](string x, string y) {
            return x + y > y + x;
        });

        string ans = "";

        for (string x : a)
            ans += x;
        
        if (ans[0] == '0')
            return "0";

        return ans;
        
    }
};