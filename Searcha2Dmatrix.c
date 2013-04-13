class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=matrix.size();
		int n=matrix[0].size();
		int i=0;
		int j=n-1;
		
		if(target<matrix[0][0] || target>matrix[m-1][n-1]) return false;
		
		while(i<m){
		    if(matrix[i][j]<target) i++;
			else if (matrix[i][j]>target) return binaryHelper(matrix[i], j,target);
			else return true;
		}
		return false;
    }
	
	bool binaryHelper(vector<int> &array, int n, int target){
	   int l=0;
	   int r=n-1;
	   while(l<=r){
	      int m=(l+r)/2;
		  if(array[m]<target) l=m+1;
		  else if (array[m]>target) r=m-1;
		  else return true;
	   }
	   
	   return false;
	}
};