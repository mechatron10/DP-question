int minimumEnergy(vector<int>& height, int n) {
       
        vector<int>dp(n);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<n;++i)
        {
            dp[i]=min(abs(height[i]-height[i-1])+dp[i-1],abs(height[i]-height[i-2])+dp[i-2]);
        }
        return dp[n-1];
    }