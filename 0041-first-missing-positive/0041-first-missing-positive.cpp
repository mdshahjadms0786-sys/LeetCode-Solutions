class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int x = 1;

        for (int n : nums) {
            if (n == x)
                x++;
        }

        return x;
    }
};