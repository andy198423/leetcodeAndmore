
class Solution { // classic method form leetcode discussion, in time O(2n)
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=num.size();
        if(n==0) return 0;
        unordered_map<int,int> table;
        int result=1;
        for(int i=0; i<n; i++) table[num[i]]=0;
        for(int i=0; i<n; i++)
        {
            if(!table[num[i]])
            {
                table[num[i]]=1;
                int len=1+findConsecutive(table,num[i]-1,-1);
                len+=findConsecutive(table,num[i]+1,1);
                result=max(result,len);
            }
        }
        return result;
    }
    
    int findConsecutive(unordered_map<int,int>& table, int num, int step)
    {
        int len=0;
        while(table.find(num)!=table.end())
        {
            len++;
            table[num]=1;
            num+=step;
        }
        return len;
    }
};



class Solution {  //better solution can solve problem in O(n)
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=num.size();
        if(n==0) return 0;
        int result=1;
        unordered_map<int,int> table;
        for(int i=0; i<n; i++)
        {
            if(table.find(num[i])!=table.end()) continue; //handle duplicated number in the unsorted array
            table[num[i]]=1;
            if(table.find(num[i]-1)!=table.end()) result=max(result,merge(table,num[i]-1,num[i]));
            if(table.find(num[i]+1)!=table.end()) result=max(result,merge(table,num[i],num[i]+1));
        }
        
        return result;
    }
    
    int merge(unordered_map<int,int>& table, int left, int right)
    {
        int lower=left-table[left]+1;
        int upper=right+table[right]-1;
        int len=upper-lower+1;
        table[lower]=len;
        table[upper]=len;
        return len;
    }
};