class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign=1;
		if (n<0){
		   sign=-sign;
		   n=-n;
		}
		double result=powHelper(x,n);
		if(sign<0) return 1.0/result;
		return result;
    }
	
	double powHelper(double x, int n){
	   if(n==0) return 1.0;
	   if(n==1) return x;
	   double t=powHelper(x,n/2);
	   if(n%2==1) return x*t*t;
	   return t*t;
	}
};
(iterative solution)
class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign=1;
		if(n<0){
		  sign=-1;
		  n=-n;
		}
		
		double result=1.0;
		double tmp=x;
		
		for(int t=n; t>0; t/=2){
		  if(t%2==1) result*=tmp;
		  tmp=tmp*tmp;
		}
		
		if(sign<0) return 1.0/result;
		return result;
    }
};