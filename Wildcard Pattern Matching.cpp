bool solver(int i,int j,string &pattern,string &str,vector<vector<int>>&dp)
    {
        if(j==str.length()&&i==pattern.length())//once we reach to the end of the strings together then we 
        //can surely say that we have matched the pattern
        {
            return true;
        }
        if(i==pattern.length())
        {
            return false;
        }
        if(j==str.length()&&i<pattern.length())
        {
            if(pattern[i]=='*')
            {
                return solver(i+1,j,pattern,str,dp);
            }
            return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool ans;
        if(pattern[i]=='*')
        {
            ans=solver(i+1,j+1,pattern,str,dp)|solver(i,j+1,pattern,str,dp)|solver(i+1,j,pattern,str,dp);
        }
        else if(pattern[i]=='?'||pattern[i]==str[j])
        {
            ans=solver(i+1,j+1,pattern,str,dp);
        }
        return dp[i][j]=ans;
    }
    int wildCard(string pattern,string str)
    {  
        int n=pattern.length();
        int m=str.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      return solver(0,0,pattern,str,dp);        
        
    }