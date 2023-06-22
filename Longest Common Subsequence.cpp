class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solver(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i>=s1.length()||j>=s2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(s1[i]==s2[j])
        {
            ans=1+solver(i+1,j+1,s1,s2,dp);
        }
        ans=max({solver(i+1,j,s1,s2,dp),solver(i,j+1,s1,s2,dp),ans});
        return dp[i][j]=ans;
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n=s1.length();
        int m=s2.length(); 
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solver(0,0,s1,s2,dp);
    }
};