//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b){
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxdead=0;
        for(int i=0;i<n;i++){
            maxdead=max(maxdead,arr[i].dead);
        }
        sort(arr,arr+n,comp);
        int c=0;
        int maxprofit=0;
        vector<int>v(maxdead+1,-1);
        for(int i=0;i<n;i++){
            int idd=arr[i].id;
            int deadd=arr[i].dead;
            int profitt=arr[i].profit;
            
            for(int k=deadd;k>0;k--){
                if(v[k]==-1){
                    c++;
                    maxprofit+=profitt;
                    v[k]=deadd;
                    break;
                   
                }
            }
        
            
        }
         vector<int>ans;
            ans.push_back(c);
            ans.push_back(maxprofit);
            return ans;
            
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends