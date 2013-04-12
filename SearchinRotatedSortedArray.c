class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l,r,m;
		l=0;
		r=n-1;
		
		while(l<=r){
		    m=(l+r)/2;
		    if(A[m]==target) return m;
			if(A[l]<A[m]){
              if(A[l]<=target && target<A[m]) r=m-1;
			  else l=m+1;
			}
            else if(A[l]>A[m]){
               if(A[m]<target && target<=A[r]) l=m+1;
			   else r=m-1;
			}
            else l++;			
		}
		
		return -1;
    }
};