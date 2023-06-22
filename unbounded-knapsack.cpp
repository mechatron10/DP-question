class Solution{
public:
    int solver(int i,int w,int *val,int *wt, vector<vector<int>>&dp)
    {
        if(i==0)
        {
          return (w/wt[i])*val[i];
        }
        if(dp[i][w]!=-1)
        {
            return dp[i][w];
        }
        int ans=INT_MIN;
        ans=max(ans,solver(i-1,w,val,wt,dp));
        if(wt[i]<=w)
        {
            ans=max(val[i]+solver(i,w-wt[i],val,wt,dp),ans);
        }
        return dp[i][w]=ans;
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return solver(n-1,w,val,wt,dp);
    }
};