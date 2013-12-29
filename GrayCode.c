class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i=0; i<n; i++){
            int leading_bit=1<<i;
            for(int j=result.size()-1; j>=0; j--){
                result.push_back(leading_bit | result[j]);
            }
        }
        return result;
    }
};