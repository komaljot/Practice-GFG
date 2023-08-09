//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        

        if(n>m)return kthElement(nums2,nums1,m,n,k);
      int n1 = n;
int n2 = m;
        
        // int left=0;
        // int right=n1;
         int left = max(0, k - m);
    int right = min(n, k);
        
        while(left<=right){
            int cut1=(left+right)>>1;
            int cut2=k-cut1;
            
            // int l1;int l2;
            // int r1;int r2;
            
            // if(cut1==0)l1=INT_MIN;else l1=nums1[cut1-1];
            // if(cut2==0)l2=INT_MIN;else l2=nums2[cut2-1];
            // if(cut1==n1)r1=INT_MAX; else r1=nums1[cut1];
            // if(cut2==n2)r1=INT_MAX; else r2=nums2[cut2];
              int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
//             int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
// int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
// int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1 + n1 - 1];
// int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2 + n2 - 1];
            
            if(l1<=r2 and l2<=r1){
                // if((n1+n2)%2==0)return (max(l1,l2)+min(r1,r2))/2.0;
                // else return max(l1,l2);
                return max(l1,l2);
            }
            else if(l1>r2)right=cut1-1;
            else left=cut1+1;
        }
        return -1;
 
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends