class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int start=0;
		int end=s.size()-1;
		while(start<end){
		    if(!isAlpha(s[start])){
			   start++;
			   continue;
			}
			
			if(!isAlpha(s[end])){
			   end--;
			   continue;
			}
			
			
		    if(s[start]==s[end] || abs((int)(s[start]-s[end]))==32){
			   start++;
			   end--;
	        }
			else return false;
			
		}
		return true;
    }
	
	bool isAlpha(char c){
	     if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) return true;
		 else return false;
	}
	
};