class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=2) return 0;
		
		int lmax[n];
		int rmax[n];
		int waterSum=0;
		
		lmax[0]=A[0];
		for(int i=1; i<n; i++) lmax[i]=(lmax[i-1]>A[i]) ? lmax[i-1]:A[i];
		
		rmax[n-1]=A[n-1];
		for(int i=n-2; i>=0;i--) rmax[i]=(rmax[i+1]>A[i]) ? rmax[i+1]:A[i];
		
		
		for(int i=1; i<n-1; i++)
		{
		   int low=(lmax[i-1]<rmax[i+1]) ? lmax[i-1]:rmax[i+1];
		   waterSum+=(low>A[i]) ? (low-A[i]):0;
		}
		
		return waterSum;
    }
};