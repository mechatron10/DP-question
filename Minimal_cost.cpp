int solver(int index,vector<int>&height,int n,int k,vector<int>&dp)
    {
        if(index>=n-1)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int cost=INT_MAX;
        for(int z=index+1;z<=index+k;++z)
        {
            if(z<=n-1)
            {
                cost=min(cost,abs(height[index]-height[z])+solver(z,height,n,k,dp));
            }
            
        }
        return dp[index]=cost;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return solver(0,height,n,k,dp);
        
    }