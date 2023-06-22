class Solution{
public:
  
    vector<int> minPartition(int n)
    {
        // code here
        //Only in the ways questions we have to keep in mind the case of the first or the last element to be 0
        //The question can solved like the unbounded knapsack problem where each of the coins can be choosed
        // any number of times as needed 
        //At last we will check is the remaining amount is factor of this last element if it will be then we will 
        //push the values those many number of times in the result
        vector<int>ans;
        vector<int>coins={1,2,5,10,20,50,100,200,500,2000};
        for(int i=9;i>=0;i--)
        {
            if(n>=coins[i])
            {
                int times=n/coins[i];
                for(int j=0;j<times;++j)
                {
                    ans.push_back(coins[i]);
                }
                n-=(times)*coins[i];
            }
        }
        return ans;
    }
};