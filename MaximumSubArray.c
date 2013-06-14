class Solution {
public:
    int maxSubArray(int A[], int n) {    // O(n) solution
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        int sum=0;
        int result=A[0];
        
        for (int i=0; i<n; i++)
        {
            sum=max(sum+A[i],A[i]);
            result=max(sum,result);
        }
        
        return result;
        
    }
};


class Solution {  // using idea of divide and conquer 
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return maxSubArrayHelper(A,0,n-1);
    }
    
    int maxSubArrayHelper(int A[], int l, int u)
    {
        if(u<l) return INT_MIN;
        if(u==l) return A[l];
        
        int m=l+(u-l)/2;
        
        int leftmax=maxSubArrayHelper(A,l,m-1);
        int rightmax=maxSubArrayHelper(A,m+1,u);
        int maxSofar=max(leftmax,rightmax);
        return max(maxSofar,mergeCompare(A,l,m,u));
    }
    
    int mergeCompare(int A[], int l, int m, int u)
    {
        int sum=0;
        int maxGol=A[m], maxGor=A[m];
        for(int i=m;i>=l;i--)
        {
            sum+=A[i];
            maxGol=max(maxGol,sum);
        }
        sum=0;
        for(int i=m;i<=u;i++)
        {
            sum+=A[i];
            maxGor=max(maxGor,sum);
        }
        
        return maxGol+maxGor-A[m];
    }
};