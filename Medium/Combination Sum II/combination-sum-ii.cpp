//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 void helper(vector<int> &candidates, int target,vector<vector<int>>&ans,int ind,vector<int>&t){
      if(target==0){
          ans.push_back(t);
          return;
      }
      for(int i=ind;i<candidates.size();i++){
          if(i>ind and candidates[i]==candidates[i-1])continue;
          if(candidates[i]>target)break;
          t.push_back(candidates[i]);
          helper(candidates,target-candidates[i],ans,i+1,t);
          t.pop_back();
      }
  }
  
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        vector<vector<int>>ans;
        vector<int>t;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,ans,0,t);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends