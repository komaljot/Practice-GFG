//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool ispossible(int arr[],int n ,int k,long long mid){
      int painter=1;
      int boards=0;
      for(int i=0;i<n;i++){
          if(arr[i]+boards<=mid){
              boards+=arr[i];
          }
          else{
              painter++;
              if(arr[i]>mid || painter>k){
                  return false;
              }
            //   boards=0;
              boards=arr[i];
              }
      }
      return true;
  }
    
    long long minTime(int A[], int N, int M)
    {
        // code here
        // return minimum time
        
        long long mid=0;
        long long i=0;
        long long sum=0;
        long long ans=-1;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        long long s=0;
        long long e=sum;
        while(s<=e){
            mid=s+(e-s)/2;
            if(ispossible(A,N,M,mid)){
                ans=mid;
                e=mid-1;
                
            }
            else s=mid+1;
            
        }
        return ans;
    
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends