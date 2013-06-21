class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=prices.size();
        if(n==0) return 0;
        int result=0;
        for(int i=0; i<n; i++)
        {
            if(prices[i]>prices[i-1]) result+=(prices[i]-prices[i-1]);
        }
        return result;
    }
};