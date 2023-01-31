//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
        int ans=INT_MAX;
        int a1=-1;int a2=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==x)a1=i;
            if(arr[i]==y)a2=i;
            
            if(a1!=-1 and a2!=-1)
            ans=min(ans,abs(a1-a2));
        }
        if(a1==-1 or a2==-1)return -1;
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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends