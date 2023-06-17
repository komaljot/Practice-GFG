//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<int>nextSmaller(long long arr[],int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 and arr[s.top()]>=arr[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(long long arr[],int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 and arr[s.top()]>=arr[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int>ns(n);vector<int>ps(n);
        ns=nextSmaller(arr,n);ps=prevSmaller(arr,n);
        long long area=LONG_MIN;
        for(int i=0;i<n;i++){
            long long l=arr[i];
            
            if(ns[i]==-1)ns[i]=n;
            
            long long b=ns[i]-ps[i]-1;
            
            long long newarea=l*b;
            if(newarea>area)area=newarea;
            // area=max(area,newarea);
            
        }
        // for(int i=0;i<n;i++)cout<<ps[i]<<" "<<ns[i]<<endl;
        return area;
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