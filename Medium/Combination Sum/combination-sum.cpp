//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&t,int ind){
    if(ind>=candidates.size()){
        if(target==0){
            ans.push_back(t);
        }
        return;
    }
    if(target>=candidates[ind]){
        t.push_back(candidates[ind]);
        //take
        helper(candidates,target-candidates[ind],ans,t,ind);
        t.pop_back();
    }

    //not take
    helper(candidates,target,ans,t,ind+1);
}
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Your code here
         vector<vector<int>>ans;
        vector<int>t;
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        helper(candidates,target,ans,t,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends