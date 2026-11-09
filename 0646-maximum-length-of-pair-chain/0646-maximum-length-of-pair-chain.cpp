class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int last = INT_MIN;

        for(int i = 0; i < pairs.size(); i++) {

            if(pairs[i][0] > last) {
                count++;
                last = pairs[i][1];
            }
        }

        return count;
    }
};