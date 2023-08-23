//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int tempmin=0;int tempmax=0;
        int maxsum=INT_MIN;int minsum=INT_MAX;
        int sum=0;
        
        for(int i=0;i<num;i++){
            sum+=arr[i];
            
            tempmax=max(tempmax+arr[i],arr[i]);
            maxsum=max(maxsum,tempmax);
            
            tempmin=min(tempmin+arr[i],arr[i]);
            minsum=min(minsum,tempmin);
        }
        
        if(sum==minsum)return maxsum;
        else return max(maxsum,(sum-minsum));
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends