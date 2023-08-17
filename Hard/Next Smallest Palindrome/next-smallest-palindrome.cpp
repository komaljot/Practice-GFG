//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    int change=1;
	    for(int i=0;i<n/2;i++){
	        if(num[i]>num[n-i-1])change=0;
	        else if(num[i]<num[n-i-1]) change =1;
	        num[n-i-1]=num[i];
	    }
	    vector<int>ans(n);
	    
	    for(int i=0;i<n;i++)ans[i]=num[i];
	    
	    int mid=n/2;
	    while(change and mid<n){
	        if(ans[mid]==9){
	            ans[mid]=0;
	            ans[n-mid-1]=ans[mid];
	        }
	        else{
	            ans[mid]++;
	            ans[n-mid-1]=ans[mid];
	            change=0;
	        }
	        mid++;
	    }
	    
	    if(change){
	        ans[0]=1;
	        ans.push_back(1);
	       
	    }
	    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends