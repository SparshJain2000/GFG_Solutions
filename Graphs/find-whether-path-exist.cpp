// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    bool util(int i,int j,vector<vector<int>> &grid,vector<vector<bool>>&vis){
        
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ) return false;
        if(grid[i][j]==0) {vis[i][j]=true;return false;}
        if(vis[i][j]) return false;
        if(grid[i][j]==2) return true;
        
        vis[i][j]=true;
        
        if(util(i+1,j,grid,vis)) return true;
        if(util(i-1,j,grid,vis)) return true;
        if(util(i,j+1,grid,vis)) return true;
        if(util(i,j-1,grid,vis)) return true;
        return false;

    }
    //Function to find whether a path exists from the source to destination.
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        // int n=grid.size();
        // int m=grid[0].size();
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1) 
                    if(util(i,j,grid,vis)) 
                        return true;
                
                
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends