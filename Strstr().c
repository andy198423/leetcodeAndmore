class Solution {
public:
    char *strStr(char *haystack, char *needle) {
	    int nlen=strlen(needle);
		int hlen=strlen(haystack);
		
		if(nlen==0) return haystack;
		if(hlen==0) return NULL;
		
		int* pattern=(int*)malloc(nlen*sizeof(int));
		getPattern(pattern, nlen, needle);
		int offset=getPosition(pattern, haystack, needle);
		delete(pattern);
		if(offset==-1) 
		{
		   return NULL;
		}
		else
		{
		return haystack+offset;
		}
    }
	
	void getPattern(int* pattern, int nlen, char* needle)
	{
	    pattern[0]=-1;
		int k=-1;
		
		for(int i=1; i<nlen; i++)
		{
		   while(k>-1 && needle[k+1]!=needle[i]) k=pattern[k];
		   
		   if(needle[k+1]==needle[i]) k=k+1;
		   
		   pattern[i]=k;
		   
		}
	}
	
	int getPosition(int* pattern, char* haystack, char*needle)
	{
	    int nlen=strlen(needle);
		int hlen=strlen(haystack);
		int k=-1;
		
		
		for(int i=0; i<hlen; i++)
		{
		   while(k>-1 && needle[k+1]!=haystack[i])  k=pattern[k];
		   
		   if(needle[k+1]==haystack[i]) k=k+1;
		   
		   if(k==nlen-1) return i-nlen+1;
		}
		
		return -1;
	}
};