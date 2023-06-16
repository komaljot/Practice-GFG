//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int pre(char ch){
        if(ch=='^')return 3;
        else if(ch=='*' or ch=='/')return 2;
        else if(ch=='+' or ch=='-')return 1;
        else return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++){
            //case 1
            if(s[i]=='(')st.push(s[i]);
            
            //case 2
            else if(s[i]==')'){
                while(st.top()!='(' and !st.empty()){
                    // if(s[i]!='(')
                    ans+=st.top();
                    st.pop();
                }
                // if(s[i]=='(')
                // st.pop();
                if(!st.empty())st.pop();
                
            }
            
            //case 3
            else if(isalnum(s[i])){
                ans+=s[i];
            }
            
            //operators
            else{
                while(!st.empty() and pre(st.top())>=pre(s[i])){
                    // if(st.top()!='(')
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
               
                
            }
            
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends