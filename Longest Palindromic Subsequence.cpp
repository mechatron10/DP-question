class Solution{
  public:
     int solver(int i,int j,string &A,string &B,vector<vector<int>>&dp)
     {
         if(i>=A.length()||j>=B.length())
         {
             return 0;
         }
         if(dp[i][j]!=-1)
         {
             return dp[i][j];
         }
         int ans=INT_MIN;
         if(A[i]==B[j])
         {
             ans=1+solver(i+1,j+1,A,B,dp);
         }
         ans=max({ans,solver(i+1,j,A,B,dp),solver(i,j+1,A,B,dp)});
         return dp[i][j]=ans;
         
     }
    int longestPalinSubseq(string A) {
        //code here
        //we have to find the longest palindromic subsequence I have already done this question somewhere
        string B=A;
        int n=A.length();
        reverse(A.begin(),A.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solver(0,0,A,B,dp);
    }
};