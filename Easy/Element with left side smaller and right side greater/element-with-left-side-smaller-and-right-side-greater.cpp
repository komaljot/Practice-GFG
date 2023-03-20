//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int>leftmax(n);leftmax[0]=arr[0];
    vector<int>rightmin(n);rightmin[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],arr[i]);
        
    }
    for(int i=n-2;i>=0;i--){
        rightmin[i]=min(rightmin[i+1],arr[i]);
        
    }
   // int ans=-1;
    for(int i=1;i<n-1;i++){
        if(arr[i]>=leftmax[i-1] && arr[i]<=rightmin[i+1]){return arr[i];}
        
    }
    return -1;
    
}