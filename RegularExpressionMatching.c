class Solution { // centering on p
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if(*p == '*') {
            return false;//error patten
        } else if (*p == '\0') {
            return *s == '\0';
        } else if (*p == '.') {
            char cpnext = *(p+1);
            if(cpnext == '*') {
                if(*(p+2) == '\0') return true;
                for(const char *snext = s; ; ++snext) {
                    bool match = isMatch(snext, p + 2);
                    if(match) return true;
                    if(*snext == '\0') return false;
                }
            } else {
                return (*s != '\0') && isMatch(s + 1,p + 1);
            }
        } else {
            //*p is a normal character
            char cpnext = *(p+1);
            if(cpnext == '*') {
                //have a star after a normal character
                for(const char *snext = s; ; ++snext) {
                    bool match = isMatch(snext, p + 2);
                    if(match) return true;
                    if(*snext != *p) return false;
                }
            } else {
                //standard situation
                return (*p == *s) && isMatch(s + 1,p + 1);
            }
        }
    }
};


class Solution { // centering on p+1
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s==NULL|| p==NULL) return false;
        
        if(*p=='\0') return *s=='\0';
        
        if(*(p+1)!='*')
        {
            if(*p=='*') return false;
            return ((*p==*s) || (*p=='.' && *s!='\0')) && isMatch(s+1,p+1);
        }
        
        while((*p==*s) || (*p=='.' && *s!='\0'))
        {
            if(isMatch(s,p+2)) return true;
            s++;
        }
        
        return isMatch(s,p+2);
    }
};