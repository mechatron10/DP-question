//0-1 knapsack unbounded
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    //can solve it using the take or not take concept but I have different ways
    int solver(int i,int w,int *wt,int *val,int &n, vector<vector<int>>&dp)
    {
    
        if(i==n||w<=0)
        {
            return 0;
        }
        if(dp[i][w]!=-1)
        {
            return dp[i][w];
        }
        int ans=0;
        // cout<<"wt[i]="<<wt[i]<<endl;
        // cout<<"w="<<w<<endl;
        if(wt[i]<=w)
        {
           ans=val[i]+solver(i+1,w-wt[i],wt,val,n,dp);
        }
        ans=max(0+solver(i+1,w,wt,val,n,dp),ans);
        //stored as we are returning it in the last 
        return dp[i][w]=ans;
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>>dp(n,vector<int>(w+1,-1));
       return solver(0,w,wt,val,n,dp);
       
    }
};