//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int key) {
        // Code here
        int s=0;
        int e=N-1;
         int mid;
        //complete the function here
        while(s<=e){
            mid=s+(e-s)/2;
            if(A[mid]==key){return true;}
            if((A[s]==A[mid]) && (A[e]==A[mid])){
                s++;e--;
            }
            else if(A[mid]>=A[s]){
                if(A[s]<=key and key<A[mid]){
                    e=mid-1;
                    
                }
                else s=mid+1;
            }
            else{
                if(A[mid]<key and key<=A[e]){
                     s=mid+1;;
                    
                }
                else e=mid-1;
                
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends