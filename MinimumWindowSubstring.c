class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tofind[128]={0};
		int hasfind[128]={0};
		
		int rstart=-1;
		int rend;
		int len=0;
		
		string result;
		
		for(int i=0; i<T.size(); i++) tofind[T[i]]++;
		
		for(int start=0, end=0; end<S.size(); end++){
		   hasfind[S[end]]++;
		   if(hasfind[S[end]]<=tofind[S[end]]) len++;
		   while(len==T.size()){
		      if((end-start)<(rend-rstart) || rstart==-1){
			     rstart=start;
				 rend=end;
			  }
			  
			  hasfind[S[start]]--;
			  if (hasfind[S[start]]<tofind[S[start]]) len--;
			  start++;
		   }
		}
		
		if(rstart==-1) result="";
		else{
		   result=S.substr(rstart,rend-rstart+1);
		}
		
		return result;
    }
};