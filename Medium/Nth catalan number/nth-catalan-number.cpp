//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        long mod=1e9+7;
        vector<long>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<dp.size();i++){
            for(int j=0;j<i;j++){
                dp[i]=(dp[i]+(dp[j]*dp[i-j-1])%mod)%mod;
            }
        }
        return (int)dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends