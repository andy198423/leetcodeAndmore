class Solution {
public:
    static const string keypad[8];
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        letterCombinationsHelper(digits,0,"");
        return result;
    }
    
    void letterCombinationsHelper(string& digits, int i, string str)
    {
        if(i==digits.size())
        {
            result.push_back(str);
            return;
        }
        
        int pos=digits[i]-'2';
        for(int j=0; j< keypad[pos].size(); j++)
        {
           letterCombinationsHelper(digits,i+1,str+keypad[pos][j]);
        }
    }  
};

const string Solution::keypad[8]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};