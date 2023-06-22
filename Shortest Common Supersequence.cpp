class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    //solver will get us the longest common subsequence length which will be used to find the final answer
    int solver(int i,int j,string &x,string &y,vector<vector<int>>&dp)
    {
        if(i>=x.length()||j>=y.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(x[i]==y[j])
        {
            ans=1+solver(i+1,j+1,x,y,dp);
        }
        ans=max({ans,solver(i+1,j,x,y,dp),solver(i,j+1,x,y,dp)});
        return dp[i][j]=ans;
        
    }
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        //Always remember the concept of take and not take 
        //both the upper case as well as the lower case letter are present 
        //we are gonna find the longest common subsequence length once we have that we know the remaining 
        //characters in the string are the ones which will be surely needed in the final subsequence
        //so the answer will be
        //Longest Common Subsequence Length---LCM length
        //longest common subsequence length + (x.length()-LCM length)+(Y.length()-LCM length)
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int temp=solver(0,0,x,y,dp);
        return temp+(m-temp)+(n-temp);
        
    }
};