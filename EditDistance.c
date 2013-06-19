class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=word1.size();
        int n=word2.size();
        
        int path[m+1][n+1];
        for(int i=1; i<=m; i++) path[i][0]=i;
        for(int j=1; j<=n; j++) path[0][j]=j;
        
        path[0][0]=0;
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                path[i][j]=min(min(path[i-1][j]+1,path[i][j-1]+1),path[i-1][j-1]+(word1[i-1]!=word2[j-1]));
            }
        }
        
        return path[m][n];
    }
};