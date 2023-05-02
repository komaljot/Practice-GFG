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
    static bool comp(Job a,Job b){
        //sorts in descending order
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        //1) sorting array in decreasing order in terms of profit!
        sort(arr,arr+n,comp);
        
        //2)find maximum deadline
        int max_deadline=INT_MIN;
        for(int i=0;i<n;i++){
            max_deadline=max(max_deadline,arr[i].dead);
        }
        vector<int>s(max_deadline+1,-1);
        int c=0;int totalprofit=0;
        
      
        for(int i=0;i<n;i++){
           int iid=arr[i].id;
           int ddead=arr[i].dead;
           int pprofit=arr[i].profit;
            
            for(int k=ddead;k>0;k--){
                if(s[k]==-1){
                    c++;
                    totalprofit+=pprofit;
                    s[k]=iid;
                    break;
                }
            }
        }
            vector<int>ans;
            ans.push_back(c);
            ans.push_back(totalprofit);
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