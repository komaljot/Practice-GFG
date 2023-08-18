//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        unordered_map<int,int>mp;
        vector<int>ans;
        int i=0;int j=0;
        // int cnt=0;
        while(j<n){
            mp[arr[j]]++;
            if(j-i+1<k){
                // mp[arr[j]]++;
                j++;
                
            }
            else if(j-i+1==k){
                ans.push_back(mp.size());
            //   j++;
                           mp[arr[i]]--;
               if(mp[arr[i]] == 0){
                   mp.erase(arr[i]);
                          }
            i++;
            j++; // 
            }
           
            // else if(j-i+1>k){
        //       mp[arr[i]]--;
        //       if(mp[arr[i]] == 0){
        //           mp.erase(arr[i]);
        //                   }
        //     i++;
        //     j++; // Increment j to adjust the window size
        //   }

            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends