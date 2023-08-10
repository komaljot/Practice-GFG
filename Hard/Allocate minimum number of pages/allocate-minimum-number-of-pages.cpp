//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int allocatemin(int A[],int N,int M,int mid){
        int stds=1;
        int pages=0;
        for(int i=0;i<N;i++){
            if(A[i]>mid)return false;
            if(A[i]+pages>mid){
                stds++;
                pages=A[i];
            }
            else{
                pages+=A[i];
            }
        }
        if(stds>M)return false;
        return true;
        
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N)return -1;
        int sum=0;
        for(int i=0;i<N;i++)sum+=A[i];
        
        int s=0;
        int e=sum;
        while(s<=e){
            int mid=(s+e)>>1;
            if(allocatemin(A,N,M,mid)){
                e=mid-1;
            }
            else s=mid+1;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends