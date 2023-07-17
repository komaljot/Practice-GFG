//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<int> prevsmaller(long long arr[], int n){
         vector<int>ps(n);
       
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>=arr[i])s.pop();
            
            if(s.empty())ps[i]=0;
            else ps[i]=s.top()+1;
            s.push(i);
        }
        return ps;
       
    }
     vector<int> nextsmaller(long long arr[], int n){
         vector<int>ns(n);
       
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]>=arr[i])s.pop();
            
            if(s.empty())ns[i]=n-1;
            else ns[i]=s.top()-1;
            s.push(i);
        }
        return ns;
       
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
         vector<int>ps(n);
        vector<int>ns(n);
       ps= prevsmaller(arr,n);
        ns=nextsmaller(arr,n);
        long long ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,(ns[i]-ps[i]+1)*arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends