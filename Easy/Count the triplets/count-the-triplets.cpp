//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    int count=0;
	    sort(arr,arr+n);
	    reverse(arr,arr+n);
	   
	
	  for(int i=0;i<n;i++){
	    int j=i+1;int k=n-1;  
	  while(j<k){
	       if(arr[j]+arr[k]==arr[i]){
	           count++;j++;k--;
	       }
	       else if(arr[j]+arr[k]>arr[i]){
	           j++;
	       }
	       else k--;
	   }
	  }
	  return count;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends