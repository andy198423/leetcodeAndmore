class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=obstacleGrid.size();
        if (m==0) return 0;
        int n=obstacleGrid[0].size();
        if(n==0) return 0;
        
        if(obstacleGrid[0][0]==1) return 0;
        
        int path[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                path[i][j]=0;
            }
        }
        
        path[0][0]=1;
        
        for(int i=1; i<m; i++) path[i][0]=(obstacleGrid[i][0]) ? 0:path[i-1][0];
        for(int j=1; j<n; j++) path[0][j]=(obstacleGrid[0][j]) ? 0:path[0][j-1];
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                path[i][j]=(obstacleGrid[i][j]) ? 0 : path[i-1][j]+path[i][j-1];
            }
        }
        
        return path[m-1][n-1];
        
    }
};