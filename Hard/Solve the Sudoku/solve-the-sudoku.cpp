//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool helper(int grid[N][N],int r,int c,int k){
        for(int i=0;i<9;i++){
            if(grid[r][i]==k)return false;
            if(grid[i][c]==k)return false;
            if(grid[3*(r/3)+i/3][3*(c/3)+i%3]==k)return false;
        }
        return true;
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                //to find empty
                if(grid[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(helper(grid,i,j,k)){
                            grid[i][j]=k;
                            if(SolveSudoku(grid)==true)return true;
                            else grid[i][j]=0;
                        }
                    }
                     return false;
                   
                }
                
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        SolveSudoku(grid);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends