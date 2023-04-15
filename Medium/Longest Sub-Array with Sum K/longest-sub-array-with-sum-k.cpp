//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        //the "better" approach
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
           if(mp.find(sum)==mp.end()) mp[sum]=i;
            
            if(sum==K){//from starting we will find
               ans=max(ans,i+1);//even if we do not write max it works! as it is from the starting
           }
           if(mp.find(sum-K)!=mp.end()){
                ans=max(ans,i-mp[sum-K]);
                
            }
          
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends