class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool result[n];
        for(int i=0;i<n;i++) result[i]=false;
        if(n<2) return true;
        int count;
        for(int i=0; i<n;)
        {
            if(A[i]==0 && !result[i+1]) break;
            else
            {
               for(int j=0; j<A[i];j++)
               {
                  if(i+j+1<n) 
                  {
                      result[i+j+1]=true;
                      count=i+j+1;
                  }
                  else count=n;
               }
            }
            i=count;
        }
        
        return result[n-1]; 
    }
};