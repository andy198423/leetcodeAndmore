class Solution { // my method, can not pass large test
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<2) return 0;
        int count=0;
        int result[n];
        for(int i=0; i<n; i++) result[i]=INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            result[i]=min(count,result[i]);
            for(int j=1; j<=A[i]; j++)
            {
                if((i+j)<(n-1))
                {
                    result[i+j]=min(result[i+j],result[i]+1);
                }
                else return (result[i]+1);
            }
    
            count++;
        }
        
        return result[n-1];
    }
};


class Solution { // better solution O(n), can pass the large test cases
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start=0;
        int end=0;
        int next=0;
        int step=0;
        
        while(end<n-1)
        {
            step++;
            for(int i=0; i<=end; i++)
            {
                next=max(next,i+A[i]);
            }
            start=end+1;
            if(next<=end) return -1; // means can not reach the end of array
            end=next;
        }
        
        return step;
    }
};