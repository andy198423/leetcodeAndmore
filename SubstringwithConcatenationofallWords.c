class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int Slen=S.size();
    	int elen=L.size();
		int ilen=L[0].size();
		vector<int> result;
		
		map<string,int> tofind;
		map<string,int> hasfind;
		
		for(int i=0; i<elen; i++) tofind[L[i]]++;
		
		for(int i=0; i<=(Slen-elen*ilen); i++)
		{
		    int j;
		    hasfind.clear();
			for(j=0; j<elen; j++)
			{
			   string temp=S.substr((i+ilen*j),ilen);
			   if(tofind.find(temp)==tofind.end()) break;
			   hasfind[temp]++;
			   if(hasfind[temp]>tofind[temp]) break;
			}
			
			if(j==elen) result.push_back(i);
		}
		return result;
    }
};