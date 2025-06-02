class Solution {
  public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&g,vector<vector<int>>&dp){
        if(i==n || j==m || g[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        return dp[i][j]=solve(i+1,j,n,m,g,dp) + solve(i,j+1,n,m,g,dp);
    }
    
    int uniquePaths(vector<vector<int>> &grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(grid[n-1][m-1]==1)return 0;
        return solve(0,0,n,m,grid,dp);
    }
};