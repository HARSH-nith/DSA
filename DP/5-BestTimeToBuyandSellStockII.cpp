class Solution {
public:
    int maxProfit(vector<int>& P) {
 int profit = 0;
        for(int i = 1; i < size(P); i++)
            if(P[i] > P[i-1])              // yesterday was valley, today is peak
                profit += P[i] - P[i-1];   // buy yesterday, sell today
        return profit;
    }
};