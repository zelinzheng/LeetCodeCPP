class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len == 0)
        {
            return 0;
        }
        if (k*2 >= len)
        {
            return helper(prices);
        }
        int global[len+1];
        
        for(int i=0;i<len+1; i++) {
            global[i] = 0;
        }
        
        global[0] = INT_MIN;
        
        for (int i = 1; i < 2*k + 1; i++)
        {
            for(int j=1; j<=len; j++) {
                global[j] = max(global[j-1], global[j] + (i%2?-1:1)*prices[j-1]);
            }
        }

        return global[len];
    }

    int helper(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            profit = max(profit, profit + prices[i + 1] - prices[i]);
        }

        return profit;
    }
    
};
