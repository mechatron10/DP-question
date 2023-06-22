class Solution {
public:
    int solver(int i,vector<int>&prices,vector<int>&dp)
    {
        // cout<<"i="<<i<<endl;
        if(i==prices.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=0;//as we can also buy and sell on the same day hence we have the profit of that day as 0
        ans=solver(i+1,prices,dp);//we can also decide not to but at any given day
        for(int j=i+1;j<prices.size();++j)
        {
            if(prices[j]>prices[i])
            {
                 ans=max(prices[j]-prices[i]+solver(j,prices,dp),ans);
            }
         }
        return dp[i]=ans;
    }
    int maxProfit(vector<int>& prices) {
       //we can decide to purchase the stock or we can decided to sell the 
       //stock at any given day 
       int n=prices.size();
       vector<int>dp(n,-1);
       return solver(0,prices,dp); 
    }
};