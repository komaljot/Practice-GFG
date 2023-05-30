//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        // if(N==0)retur
        if(N==0)return -1;
        if(N==1)return 1;
        // int pos=1;
        // while(N>0){
        //     if(N&1)return pos;
        //     N=N>>1;
        //     pos++;
            
        // }
        
        int p=0;
        while(N>=pow(2,p)){
            if(N==pow(2,p)){
                return p+1;
            }
            p++;
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends