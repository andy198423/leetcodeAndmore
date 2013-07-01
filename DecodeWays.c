class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n==0) return 0;
        if(s[0]=='0') return 0;
        int result[n+1];
        result[0]=1;
        result[1]=1;
        
        for (int i=2; i<=n; i++)
        {
            if(s[i-2]!='0' && s[i-1]!='0')
            {
                if( s[i-2]<'2'|| (s[i-2]=='2' && s[i-1]<='6')) result[i]=result[i-1]+result[i-2];
                else result[i]=result[i-1];
            }
            else if(s[i-1]=='0' && s[i-2]!='0' && s[i-2]<='2') result[i]=result[i-2];
            else if(s[i-1]!='0' && s[i-2]=='0') result[i]=result[i-1];
            else return 0;
            
        }
        
        return result[n];
    }
};