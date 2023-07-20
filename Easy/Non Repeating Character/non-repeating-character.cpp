//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
    //   unordered_map<int,pair<char,int>>mp;
    unordered_map<char, std::pair<int, int>> mp;
       for(int i=0;i<S.length();i++){
        //   mp.insert(i,{S[i],mp[S[i]]++});
        mp[S[i]].first = i;
        mp[S[i]].second++;
       }
    //   int k=99;
    //   char c='#'; 
    //   for(auto it:mp){
    //       int f=it.first;
    //       char s=it.second.first;
    //       int m=it.second.second;
    //       if(m==1 and f<k ){
    //           k=f;
    //           c=s;
    //       }
           
    //   }
    //   return c;
       
    // }
    int k = S.length(); // Initialize k with the length of the string
    char c = '$';       // Default return character if no non-repeating character is found

    for (auto it : mp)
    {
        int f = it.second.first;
        int m = it.second.second;
        if (m == 1 && f < k)
        {
            k = f;
            c = it.first;
        }
    }
    // if(c=)
    return c;
}
// Changed correctly find the first non-repeating character in the given string.








};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends