class Solution{
  public:
     int solver(int length,int *price,vector<int>&dp)
     {
        //  if(length==0)
        //  {
        //      return 0;
        //  }
        // cout<<"length="<<length<<endl;
        if(dp[length]!=-1)
        {
            return dp[length];
        }
         int ans=price[length-1];//this means the zero length cut
         for(int cut=1;length-cut>0;cut++)
         {
          ans=max(ans,solver(length-cut,price,dp)+solver(cut,price,dp));   
         }
         return dp[length]=ans;
     }
    int cutRod(int price[], int n) {
        //code here
        //is is same as the coin denominations problem
        //may be the greedy approach will work here
        vector<int>dp(n+1,-1);
        return solver(n,price,dp);
    }
};