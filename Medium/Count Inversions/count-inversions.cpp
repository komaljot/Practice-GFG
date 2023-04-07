//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int  merge(long long arr[],long long temp[],long long left,long long mid,long long right){
        long long  i=left;
        long long  j=mid;
        long long  k=left;
        long long  invc=0;
        while((i<=mid-1) and (j<=right)){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                invc+=mid-i;
                temp[k]=arr[j];
                k++;j++;
            }
        }
        while(i<=mid-1){
            temp[k++]=arr[i++];
        }
        while(j<=right){
             temp[k++]=arr[j++];
        }
        
        for(int i=left;i<=right;i++){
            arr[i]=temp[i];
        }
        return invc;
    }
    
    
    long long int mergeSort(long long arr[], long long temp[],long long  left,long long right){
        long long mid,invc=0;
        if(right>left){
       mid = (left + right)/2;

        invc += mergeSort(arr,temp,left,mid);
        invc += mergeSort(arr,temp,mid+1,right);

        invc += merge(arr,temp,left,mid+1,right);
    }
    return invc;
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSort(arr,temp,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends