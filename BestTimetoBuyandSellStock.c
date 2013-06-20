class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=prices.size();
        if(n==0) return 0;
        int low=0;
        int maxrev=INT_MIN;
        for (int i=0; i<n; i++)
        {
            if(prices[i]<prices[low]) low=i;
            if((prices[i]-prices[low])>maxrev) maxrev=prices[i]-prices[low];
        }
        
        return maxrev;
    }
};