class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(2,-1);
		int l=lower_bound(A,n,target);
		int r=upper_bound(A,n,target);
		if(r>=l){
		  result[0]=l;
		  result[1]=r;
		}
		
		return result;
    }
	
	int lower_bound(int A[], int n, int target){
        int l=0;
        int r=n-1;
        while(l<=r){
		  int m=(l+r)/2;
          if(target<=A[m]) r=m-1;
		  else l=m+1;
		}
         return r+1;//left to the begin of the target
	}
	
	int upper_bound(int A[], int n, int target){
	    int l=0;
		int r=n-1;
		while(l<=r){
		   int m=(l+r)/2;
		   if(target>=A[m]) l=m+1;
		   else r=m-1;
		}
		return l-1; // right to the begin of the target
	}
};