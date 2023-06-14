//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<int>s;
        for(int i=0;i<x.length();i++){
            //if opening bracket
            if(x[i]=='[' or x[i]=='(' or x[i]=='{'){
                s.push(x[i]);
            }
            
            //closing bracket!
           
           
            else{
                if (s.empty())return false;
                if((x[i]=='}' and s.top()=='{') or
                (x[i]==']' and s.top()=='[') or
                (x[i]==')' and s.top()=='(')){
                    s.pop();
                }
                
                else return false;
                
            }
        
        }
        if(s.empty())return true;
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends