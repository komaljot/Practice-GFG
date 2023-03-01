//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(vector<int>& height, int ind, int k,vector<int>&dp){
      if(ind==0)return 0;
      if(dp[ind]!=-1)return dp[ind];
      int mini=INT_MAX;int fe=0;
      for(int j=1;j<=k;j++){
          if(ind-j>=0)
       fe=f(height,ind-j,k,dp)+abs(height[ind]-height[ind-j]);
      mini=min(mini,fe);
          
      }
      return dp[ind]=mini;
     
      
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return f(height,n-1,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends