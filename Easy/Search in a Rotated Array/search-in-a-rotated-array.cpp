//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int s, int e, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        int mid;
        //complete the function here
        while(s<=e){
            mid=s+(e-s)/2;
            if(A[mid]==key)return mid;
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
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends