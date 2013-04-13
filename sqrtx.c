class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<2) return x;
		
		int l=0;
		int r=1+(x/2);
		while((l+1)<r){
		   long long m=(l+r)/2;
		   long long p=m*m;
		   if(p>x) r=m;
		   else if(p<x) l=m;
           else return m;		   
		}
		
		return l;
    }
};