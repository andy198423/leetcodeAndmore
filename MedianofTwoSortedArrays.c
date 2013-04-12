class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(((m+n)%2)==0) {
           double a=findMedianSortedArraysHelper(A,m,B,n,(m+n)/2);
		   double b=findMedianSortedArraysHelper(A,m,B,n,(m+n)/2+1);
		   return (a+b)/2.0;
		}
        else return findMedianSortedArraysHelper(A,m,B,n,(m+n)/2+1);		
    }
	
	double findMedianSortedArraysHelper(int A[], int m, int B[], int n, int k){
	    if(m<=0) return B[k-1]; 
		if(n<=0) return A[k-1]; 
		
		int i=(double)m/(m+n)*k-1;
		int j=(k-1)-i;
		
		int Ai_1=(i==0) ? INT_MIN:A[i-1];
		int Bj_1=(j==0) ? INT_MIN:B[j-1];
		int Ai  =(i==m) ? INT_MAX:A[i];
		int Bj  =(j==n) ? INT_MAX:B[j];
		
		if((Bj_1<=Ai) && (Ai<=Bj)) return A[i];
		if((Ai_1<=Bj) && (Bj<=Ai)) return B[j];
		
		if(Ai<Bj) return findMedianSortedArraysHelper(A+i+1, m-i-1, B, n, k-i-1);
		else return findMedianSortedArraysHelper(A, m, B+j+1, n-j-1, k-j-1);
	}
};