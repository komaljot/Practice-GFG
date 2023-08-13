//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  
 
    int nthFibonacci(int n){
        // code here
    //     long long f=1;
    //     long long s=1;
      
    //     if(n==1 or n==2)return 1;
        
    //     long long mod=1e9+7;
    //   for(int i=3;i<=n;i++){
    //       long long curr=(f+s)%mod;
    //       f=s;
    //       s=curr;
    //   }
    //     return f;
 
        // code here
        if(n==1 or n==2){
            return 1;
        }
    //   return (nthFibonacci(n-1)+nthFibonacci(n-2))%1000000007;
    long long mod=1e9+7;
    long long prev=1;
    long long pprev=1;
    for(int i=3;i<=n;i++){
        long long curr=(prev+pprev)%mod;
        
        pprev=prev;
        prev=curr;
    }
        return prev;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends