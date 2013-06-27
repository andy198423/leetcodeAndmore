class Solution { // recursive solution
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return numTreesHelper(n);
    }
    
    int numTreesHelper(int n)
    {
        if(n<2) return 1;
        int num=0;
        for(int i=1; i<=n; i++)
        {
            num+=numTrees(i-1)*numTrees(n-i);
        }
        
        return num;
        
    }
};


class Solution {  // iterative solution
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<2) return 1;
        int num[n+1];
        memset(num, 0, (n+1)*sizeof(int)); // important since the num[2] is used and have to be initialized to 0
        num[0]=1;
        num[1]=1;
        
        for(int i=2; i<=n; i++)  // i represents how many numbers in an array
        {
            for(int j=0; j<i; j++) // j represents the position of the root 
            {
                num[i]+=num[j]*num[i-j-1];
            }
        }
        
        return num[n];
    }
};