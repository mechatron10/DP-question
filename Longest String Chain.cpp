class Solution {
  public:
   static bool cmp(string &a,string &b)
   {
       return a.length()<b.length();
   }
    int longestChain(int n, vector<string>& word) {
        // Code here
        //we have to get the length of this longest possible sequence of words 
        //only if the length differnece between the words is 1 then only we can make the word predecessor
        //of other word 
        sort(word.begin(),word.end(),cmp);
        // for(auto x:word)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        vector<int>dp(n,1);
        int ans=1;
        for(int i=0;i<n;++i)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(abs(word[i].length()-word[j].length())==1)
                {
                    int count=0;
                    int temp=0;//for the ith string this is the pointer
                    bool flag=true;
                     for(int z=0;z<word[i].length()&&temp<word[j].length();++z)
                     {
                       if(word[i][z]!=word[j][temp]&&count==0)
                       {
                           count++;
                           temp--;
                       }
                       else if(word[i][z]!=word[j][temp]&&count>=1)
                       {
                           flag=false;
                           break;
                       }
                       temp++;
                     }
                     if(flag)
                     {
                         dp[i]=max(dp[i],1+dp[j]);
                         ans=max(ans,dp[i]);
                     }
                
                }
               
            }
        }
        return ans;
    }
};