//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int s, int e)
    {
        // Your code here
        int mid;
        while(s<e){
             if(arr[s]<arr[e])return arr[s];
            mid=s+(e-s)/2;
           
            if(arr[mid]>=arr[s])s=mid+1;
            else e=mid;
           // else s++;
        }
        return arr[s];
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends