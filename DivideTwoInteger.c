class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign=1;
		unsigned int unsigned_dividend, unsigned_divisor;
		if(dividend<0) {
		  unsigned_dividend=-dividend;
		  sign=-sign;
		}
		else unsigned_dividend=dividend; 
		
		if(divisor<0){
		  unsigned_divisor=-divisor;
		  sign=-sign;
		}
		else unsigned_divisor=divisor;
		
		unsigned int unsigned_result=unsignedDivide(unsigned_dividend,unsigned_divisor);
		
		return sign*unsigned_result;
    }
	
	unsigned int unsignedDivide(unsigned int dividend, unsigned int divisor){
	   unsigned int result=0;
	   while(divisor<=dividend){
	      unsigned int shift=0;
		  unsigned int tmp=divisor; 
		  while((((unsigned long long)tmp)<<1)<=dividend){   // in case of overflow(>INT_MAX when decide the while) have to use long long 
		     tmp<<=1;
			 shift++;
		  }
		  dividend-=tmp;
		  result|=(1<<shift);
	   }
	   
	  return result;
	}
};