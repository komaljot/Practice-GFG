//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        // code here
        // if(N<M)return M;
        // if(N/M==0)return N;
        // else{
        //     int rem=abs(N%M);
        //     return N-rem;
        // }
        // return -1;
      //  return round(N/M)*M;
          float q = round(N / float(M));

    return q * M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends