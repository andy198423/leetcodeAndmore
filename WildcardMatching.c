class Solution {   // this recursive method can not pass the large test since the running time 
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s==NULL || p==NULL) return false;
        
        if(*s=='\0') 
        {
            while(*p=='*')
            {
                p++;
            }
            
            return *p=='\0';
        }
        
        if(*p!='*')
        {
            return ((*p==*s) || (*p=='?' && *s!='\0')) && isMatch(s+1,p+1);
        }
        
        while(*s!='\0')
        {
            if(*(p+1)!='*')
            {
                if((*s==*(p+1) || *(p+1)=='?' )&& isMatch(s,p+1)) return true;
                else s++;
            }
            else p++;
        }
        
        return isMatch(s,p+1);
    }
};


class Solution {  // iterative solution can pass the large test
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s && !p) return true;
        
        const char* start_s=NULL;
        const char* start_p=NULL;
        
        while(*s)
        {
            if(*p=='?' || *p==*s)
            {
                p++;
                s++;
            }
            else if(*p=='*')
            {
                while(*p=='*') p++;
                if(!*p) return true;
                start_s=s;
                start_p=p;
            }
            else if((!*p || *p!=*s) && start_p)
            {
                s=++start_s;
                p=start_p;
            }
            else return false;
        }
        
        while(*p)
        {
            if(*p!='*') return false;
            p++;
        }
        
        return true;
    }
};

class Solution {   // this dp method can not pass the large test since the running time is long
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!p && !s) return true;
        
        int n=0;
        int m=0;
        const char* ss=s;
        const char* pp=p;
        while(*ss!='\0') 
        {
            n++;
            ss++;
        }
        n++;
        while(*pp!='\0')
        {
            m++;
            pp++;
        }
        m++;
        ss=s;
        pp=p;
        
        bool result[m+1][n+1];
        for(int i=1; i<=m; i++) result[i][0]=false;
        for(int i=1; i<=n; i++) result[0][i]=false;
        result[0][0]=true;
        
        for(int i=1; i<=m; i++)
        {
            s=ss;
            for(int j=1; j<=n; j++)
            {
                if(*p=='*')
                {
                    result[i][j]=((result[i-1][j-1]) || (result[i][j-1]));
                }
                else
                {
                    if(*(p-1)=='*') // this case include the '*' represents empty character sequence
                    {
                        int backcount=1;
                        while(*(p-backcount)=='*') backcount++;  // this case include multiple '*' which all represents the empty character sequence
                        result[i][j]=(((*p==*s)||(*p=='?')) && ((result[i-1][j-1])|| (result[i-backcount][j-1])));
                    }
                    else result[i][j]=(((*p==*s)||(*p=='?')) && (result[i-1][j-1]));
                }
                s++;
            }
            p++;
        }
        
        return result[m][n];
    }
};