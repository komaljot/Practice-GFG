//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

// class Solution 
// {
//     public:
//     bool allocatebooks(int A[], int N, int M, int mid){
//         int stds=1;
//         int pages=0;
//         for(int i=0;i<N;i++){
//             if(mid<A[i])return false;
//             if(A[i]+pages>mid){
//                 pages+=A[i];
//                 stds++;
//             }
//             else pages+=A[i];
//         }
//         if(stds>M)return false;
//         else return true;
//     }
    
//     //Function to find minimum number of pages.
//     int findPages(int A[], int N, int M) 
//     {
//          sort(A,A+N);
        
//         int sum=0;
//         for(int i=0;i<N;i++){
//             sum+=A[i];
//         }
//         //setting the search space
//         int s=0;
//         int e=sum;
//         int ans=-1;
//         int mid;
//         while(s<=e){
//             mid=s+(e-s)/2;
//             if(allocatebooks(A,N,M,mid)){
//                 ans=mid;
//                 e=mid-1;
                
//             }
//             else s=mid+1;
            
//         }
//         return ans;
//     }
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isPossible(int arr[],int n,int m,int mid){
        int pages=0;
        int stds=1;
        for(int i=0;i<n;i++){
            if(pages+arr[i]<=mid){
                 pages+=arr[i];
            }
            else{
                stds++;
                if(stds>m || arr[i]>mid)return false;
                 pages=0;
                 pages+=arr[i];
            }
           
        }
        return true;
    }
    
    
    int findPages(int A[], int n, int m) 
    {
        //code hereif(M>N)return -1;
        if(m>n)return -1;
        int s=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            
        }
        int e=sum;
        int ans=-1;
        int mid=0;
        while(s<=e){
            mid=s+(e-s)/2;
            if(isPossible(A,n,m,mid)){
                
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
        
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