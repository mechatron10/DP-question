class Solution{
  public:	
    int mod=1e9+7;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    //This is an important question
	    //The approach to solve this question is to store the previous occurences of the characters of the string 
	    //that repeat and then combine them wi
	    int n=s.length();
	    vector<int>last(26,-1);//this array will store the index of the last occurence of any particular character
	    //if it has occured else it will store -1 for all the characters
	    vector<long long >dp(n+1,0);//store the answer at any given index
	    dp[0]=1;//empty set will always contribute 1 unique subset
	    //The concept of the problem is that for every repeated occurence of a character the number of 
	    //the no. of duplicate subsets that it will contribute can be found using that character's last 
	    //occurence
	    for(int i=1;i<=n;++i)
	    {
	        if(last[s[i-1]-'a']==-1)
	        {
	            dp[i]=2*((dp[i-1])%mod);
	            dp[i]%=mod;
	            last[s[i-1]-'a']=i;
	        }
	        else
	        {
	            int index=last[s[i-1]-'a'];
	            dp[i]=((2*dp[i-1])%mod-dp[index-1])%mod;
	            dp[i]%=mod;
	            last[s[i-1]-'a']=i;
	        }
	    }
	    if(dp[n]<0)
	    {
	        dp[n]+=mod;
	    }
	    return dp[n];
	}
};