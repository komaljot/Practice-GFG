//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
 
    
    int countWays(int n)
    {
        // your code here
        vector<int>dp(n+1);
      
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];  
        
        int prev1=1;int prev2=1;
        for(int i=2;i<=n;i++){
            int curri=(prev2+prev1)%1000000007;
            
            prev2=prev1;
            prev1=curri;
        }
        return prev1;
        
        
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends