class Solution {
public:

    int solver(int i,int prev,vector<int>&arr1,vector<int>&arr2,map<pair<int,int>,int>&dp)
    {
       if(i>=arr1.size())
       {
         return 0;//if we reach the end of the array then we have no ways left to consider 
       } 
       if(dp.find({i,prev})!=dp.end())
       {
           return dp[{i,prev}];
       }
        int ans=INT_MAX/2;//because we have to avoid the overfolow
        //we are finding the upper_bound of the previous number which was considered  
        int id=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
       if(arr1[i]>prev)//only if the current is greater than the previous we can keep it as it is 
       {
         ans=min(ans,solver(i+1,arr1[i],arr1,arr2,dp));
       }
       if(id<arr2.size())//we are fiding the upper_bound of the previous element and only if the upper_bound is not the arr2.end() then only we can make the prev equal to it 
       {
           ans=min(ans,1+solver(i+1,arr2[id],arr1,arr2,dp));
       }
      return dp[{i,prev}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
      sort(arr2.begin(),arr2.end());
      map<pair<int,int>,int>dp;
      int ans= solver(0,INT_MIN,arr1,arr2,dp);
      return ans>=INT_MAX/2?-1:ans;
    }
};