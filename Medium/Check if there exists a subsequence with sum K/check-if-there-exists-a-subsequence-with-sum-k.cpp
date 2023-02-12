//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool f(int n,int i, int &k,int s,vector<int>& arr){
        if(s>k)return false;
        if(i==n){
            if(s==k)return true;
            else return  false;
        }
        //else return false;
        
        s+=arr[i];
        if(f(n,i+1,k,s,arr))return true;
        s-=arr[i];
        if(f(n,i+1,k,s,arr))return true;
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return f(n,0,k,0,arr);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends