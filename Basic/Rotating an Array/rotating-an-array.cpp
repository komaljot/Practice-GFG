//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        
        //the below gives tle
        // while(d>0){
        //     int i=0;
        //     int ele=arr[0];
        //     while(i<n-1){
             
        //     arr[i]=arr[i+1];
        //     i++;
                
        //     }
        //     arr[n-1]=ele;
        //     d--;
            
        // }
        
        //using stl rotate
        rotate(arr,arr+d,arr+n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends