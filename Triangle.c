class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.empty()) return 0;
        int m=triangle.size();
        
        for(int i=m-2; i>=0; i--)
        {
            int n=triangle[i].size();
            
            for (int j=0;j<n;j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
        
    }
};