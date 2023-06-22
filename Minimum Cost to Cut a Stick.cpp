class Solution {
public:
    int solver(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
       // cout<<"i="<<i<<"j="<<j<<endl;
         if(abs(i-j)<=1)
         {
             return 0;
         }
         if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
         int ans=INT_MAX;
         for(int k=i+1;k<j;k++)
         {
             ans=min(ans,cuts[j]-cuts[i]+solver(i,k,cuts,dp)+solver(k,j,cuts,dp));
         }
         return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        //we have to return the minimum cost of the cuts so to minimize the answer globally we will use the dynamic programming and the cuts must be arranged in ascending order of the points so that each cut is independent of the other cut this makes this a problem of partition dp where the cost of one partition will not depend on the other 
        //one part must not be dependent on other which will be possible by the sorting of the cuts and then since one part after cut become independent of other hence now we can minimize the cost of each of the parts now 
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m=cuts.size()-1;
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solver(0,m,cuts,dp);
    }
};