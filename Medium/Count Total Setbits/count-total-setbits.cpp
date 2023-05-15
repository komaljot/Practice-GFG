//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  long long powerr(long long i){
      long long x=0;
      while((1<<x)<=i){
          x++;
      }
      return x-1;
  }
    long long countBits(long long n) {
        // code here
        if(n==0)return 0;
       long long x=powerr(n);
    //   long long ans=0;
       long long ans=(x*(1<<(x-1))) + (n-(1<<x)+1) + countBits(n-(1<<x));
       return ans;
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends