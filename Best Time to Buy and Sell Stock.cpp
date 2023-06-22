class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[prices.size()-1];
        int ans=INT_MIN;
        for(int i=prices.size()-2;i>=0;i--)
        {
            ans=max(ans,m-prices[i]);
            m=max(prices[i],m);
        }
       return ans<=0?0:ans;
    }
};