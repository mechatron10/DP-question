   int countWays(int n)
    {
        // your code here
        //We can solve this questin using the bottom up approach by defining the number of ways we can reach
        //to a particular stair by the starts that are below it 
        int mod=1e9+7;
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i)
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n]%mod;
        
    }
    