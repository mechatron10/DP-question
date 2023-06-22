class Solution {
public:
    int solver(int i,bool flag,int tran,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(i==prices.size()||tran==0)
        {
            return 0;
        }
        if(dp[i][flag][tran]!=-1)
        {
            return dp[i][flag][tran];
        }
        int ans=INT_MIN;
        if(flag==1)
        {
    ans=max(-prices[i]+solver(i+1,0,tran,prices,dp),solver(i+1,1,tran,prices,dp));
        }
        else 
        {
    ans=max(prices[i]+solver(i+1,1,tran-1,prices,dp),solver(i+1,0,tran,prices,dp));
        }
        return dp[i][flag][tran]=ans;
    }

    int maxProfit(vector<int>& prices) {
     //lets solve this using the flag which indicates that whether we can buy or we can sell the stock if we keep the two   
     //lets do it 
     //flag value of the 1 indicates that we can buy the stocks
     int n=prices.size();
vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
     return solver(0,1,2,prices,dp);
    }
};