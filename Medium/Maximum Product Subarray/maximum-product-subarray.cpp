//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	     long long ans=nums[0];
        long long maxi=ans;
        long long mini=ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(maxi,mini);
            maxi=max((long long)nums[i],maxi*nums[i]);
            mini=min((long long)nums[i],mini*nums[i]);

            ans=max(maxi,ans);
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends