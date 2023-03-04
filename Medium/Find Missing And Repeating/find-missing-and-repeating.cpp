//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int re=-1;
        int me=n+1;
        int *ans=new int[2];
        //for finding repeating number
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                re=abs(arr[i]);
            }
           else  arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            
        }
        for(int i=0;i<n;i++){
            if(arr[i]>=0)me=i+1;
        }
        ans[0]=re;ans[1]=me;
        return ans;
        
        // unordered_map<int,int>mp;
        // for(int i=0;i<n;i++){
        //     mp[arr[i]]++;
            
        // }
        // for(int i=0;i<=n;i++){
        //     if(mp[i]==2)re=i;
        //     if(mp[i]==0)me=i;
            
        // }
        // ans[0]=re;ans[1]=me;
        // return ans;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends