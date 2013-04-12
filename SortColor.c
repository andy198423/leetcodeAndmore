class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start=0;
    	int end=n-1;
		int current=0;
		
	    while(current<=end){
		   if(current<start){
		      current=start;
              continue;
		   }
		   
		   if(A[current]==0)
		   {
		      swap(A[current],A[start]);
			  start++;
			  continue;
		   }
		   
		   if(A[current]==1){
		     current++;
			 continue;
		   }
		   
		   if(A[current]==2){
		     swap(A[current],A[end]);
			 end--;
		   }
		}
    }
};