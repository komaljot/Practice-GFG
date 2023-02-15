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
    void helper(vector<int> &A,int n, int B,vector<int>&t,vector<vector<int>>&ans,int ind){
        //base case
        
        if(ind==n){
            if(B==0){//sort(t.begin(),t.end());
            ans.push_back(t);}
            return;
        }
        
        //using same element
        if(A[ind]<=B){
            //pushing the element
            t.push_back(A[ind]);
            helper(A,n,B-A[ind],t,ans,ind);
            //removing that element
            t.pop_back();
        }
       // using next element
        helper(A,n,B,t,ans,ind+1);
    }
    
    
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int>t;
        sort(A.begin(),A.end());

        A.erase(unique(A.begin(),A.end()),A.end());
        helper(A,A.size(),B,t,ans,0);
       
        //sort(ans.begin(),ans.end());
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