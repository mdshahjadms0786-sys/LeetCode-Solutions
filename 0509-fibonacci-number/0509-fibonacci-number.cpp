class Solution {
public:
    int fib(int n) {
       if(n==0) return 0;
       if(n==1) return 1;

       int ans=0, p1=1, p2=0;

       for(int ctr=2; ctr<=n; ctr++){
        ans=p1+p2;
        p2=p1; p1=ans;
       }
       return ans;

    }
};