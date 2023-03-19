//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
    //   sort(arr,arr+n);

    
// set<int>s;
// for(int i=0;i<n;i++){
//     s.insert(arr[i]);
// }
      
    //   for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
      
    //   int count=1;  int mc=1;
      
    //   for(int i=0;i<n;i++){
    //       if(arr[i]==arr[i+1])continue;
    //       if(arr[i]==arr[i]+1){
    //           count++;
    //           mc=max(mc,count);
    //       }
    //      else count=1;
          
    //   }
    // //   cout<<mc+1<<" ";
    //   return mc;
     int maxi = 1;

    int count = 1;

    sort(arr,arr+N);

    // set<int> res (arr, arr+N);

    

    for(int i = 0 ; i<N ; i++){

        if(arr[i+1] == arr[i])continue;

        if(arr[i+1]==arr[i]+1){count++; maxi = max(maxi,count);}

        else count =1 ;

    }

    

    return maxi;

    

 
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends