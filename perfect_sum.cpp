class Solution{

	public:
	int mod=1e9+7;
	int solver(int i,int sum,int *arr,int &n,int &required, vector<vector<int>>&dp)
	{
	    if(i==n)
	    {
	        return (sum==required)?1:0;
	    }
	    if(sum>required)
	    {
	        return 0;
	    }
	    if(dp[i][sum]!=-1)
	    {
	        return dp[i][sum];
	    }
	    int ans=(solver(i+1,sum,arr,n,required,dp)%mod+solver(i+1,sum+arr[i],arr,n,required,dp)%mod)%mod;
	    return dp[i][sum]=ans;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        //we just have to find the no . of subsets that have a sum which is exactly equal to the sum
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solver(0,0,arr,n,sum,dp);
	}
	  
};