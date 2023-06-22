class Solution{
		

	public:
	int solver(int i,int j,string &a,string &b,vector<vector<int>>&dp)
	{
	    if(i==a.length())//if we reach to the end of the first then we just inserting the remainig elements
	    //directly
	    {
	        return b.length()-j;
	    }
	    if(j==b.length())//if we reach to the end of the string second first then we will just remove 
	    //remaining characters from a
	    {
	        return a.length()-i;
	    }
	    if(dp[i][j]!=-1)
	    {
	        return dp[i][j];
	    }
	    int ans=INT_MAX;
	    if(a[i]==b[j])
	    {
	        ans=min({ans,solver(i+1,j+1,a,b,dp),1+solver(i+1,j,a,b,dp),1+solver(i,j+1,a,b,dp)});
	    }
	    else
	    {
	        ans=min({ans,1+solver(i,j+1,a,b,dp),1+solver(i+1,j,a,b,dp)});
	        //if not equal then we can only insert or delete 
	        //Here inserting is the insertion of the character at the jth position before the ith position
	        //it is already equal to the jth character hence we call for the state 1+solver(i,j+1,a,b)
	        //as the previous to the ith character is the jth character which will be inserted
	    }
	    return dp[i][j]=ans;
	}
	int minOperations(string a, string b) 
	{ 
	    // Your code goes here
	    int n=a.length();
	    int m=b.length();
	    //convert it into the bottom up approach
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	   // for(int j=0;j<=n;++j)
	   // {
	   //     dp[n][j]=m-j;
	   // }
	   // for(int i=0;i<=n;++i)
	   // {
	   //     dp[i][m]=n-i;
	   // }
	   // for(int i=n-1;i>=0;i--)
	   // {
	   //     for(int j=m-1;j>=0;j--)
	   //     {
	            
	   //     }
	   // }
	    return solver(0,0,a,b,dp);
	    
	} 
};