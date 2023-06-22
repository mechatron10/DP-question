 int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        if(grid[0][0]==1)
        {
            return 0;
        }
        //cout<<"yes"<<endl;
        int mod=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
         dp[1][1]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                // cout<<i<<j<<endl;
                if(i==1&&j==1)
                {
                    continue;
                }
                if(grid[i-1][j-1]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                
            }
        }
        return dp[n][m];
    }