class Solution {
  public:
    int solver(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(j==t.length())
        {
            return s.length()-i;//we are returning this because we will remove all the remaining characters
            //in the s string if any remaining once we have formed the string j comletely
        }
        if(i==s.length())
        {
            return t.length()-j;//if I reach to the end of the string s which is to be converted into t but
            //I have not reached to the end of the string t  then it means that remaining characters can 
            //be inserted directly at the end this is a possible case
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
         if(s[i]==t[j])
        {
            ans=min({ans,1+solver(i,j+1,s,t,dp),1+solver(i+1,j,s,t,dp),solver(i+1,j+1,s,t,dp)});
        }
        else
        {
            ans=min({ans,1+solver(i,j+1,s,t,dp),1+solver(i+1,j,s,t,dp),1+solver(i+1,j+1,s,t,dp)});
        }
        //1+solver(i,j+1,s,t)--it is for  the insertion operation(means insertion at the i-1 position of character
        //equal to the jth character)
        //1+solver(i+1,j,s,t)--It is for the removal(Removing the current character)
        //1+solver(i+1,j+1,s,t)--it is for the replacing operation(Replacing the current character with the character
        //equal to the jth character if the ith and the jth character are not equal )
        
        return dp[i][j]=ans;
        
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solver(0,0,s,t,dp);
    }
};