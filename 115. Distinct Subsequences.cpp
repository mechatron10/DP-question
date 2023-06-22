class Solution {
public:
    int solver(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(j<0)
        {
          return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j]=solver(i-1,j-1,s,t,dp)+solver(i-1,j,s,t,dp);// if we have a match we can either choose to match or not match
        }
        return dp[i][j]=solver(i-1,j,s,t,dp);//if we do not have a match we will have to consider only this case
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solver(n-1,m-1,s,t,dp);
    }
};