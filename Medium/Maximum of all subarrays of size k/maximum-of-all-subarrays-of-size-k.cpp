//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        // // your code here
        // vector<int>ans;
        // if(n==1){
        //     ans.push_back(arr[0]);return ans;}
        // int maxi=INT_MIN;
        // for(int i=0;i<=k-1;i++){
        //     maxi=max(maxi,arr[i]);
            
        // }
        // ans.push_back(maxi);
        // int i=k-1;
        // int j=i+1;
        // while(j<n){
        //     maxi=max(maxi,arr[j]);
        //     ans.push_back(maxi);
        //     i++;j++;
        // }
        // return ans;
         deque<int>dq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            //out of bound indexes
            if(!dq.empty() and dq.front()==i-k)dq.pop_front();

            //this will help us to maintain dec order sequence
            while(!dq.empty() and nums[dq.back()]<=nums[i])dq.pop_back();

            dq.push_back(i);

            if(i>=k-1)ans.push_back(nums[dq.front()]);


        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends