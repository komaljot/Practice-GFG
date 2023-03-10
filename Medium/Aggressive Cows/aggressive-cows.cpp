//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
bool helper(int n, int k, vector<int> &stalls,int s){
    int cord=stalls[0];int cnt=1;
    for(int i=1;i<n;i++){
        if(stalls[i]-cord>=s){
            cord=stalls[i];
            cnt++;
        }
        if(cnt==k)return true;
    }
    return false;
    
    
}


    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int ans=0;
        //setting the search space
        int s=1;
        int e=stalls[n-1]-stalls[0];
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            
            //if we find any one with the number
            if(helper(n,k,stalls,mid)){
                ans=mid;
                //to maximise
                s=mid+1;
            }
            else e=mid-1;
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends