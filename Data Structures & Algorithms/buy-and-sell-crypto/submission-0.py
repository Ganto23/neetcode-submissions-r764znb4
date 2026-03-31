class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0

        start = 0

        for end in range(len(prices)):
            start = 0
            max_profit = max(max_profit,prices[end]-prices[start])
            
            while start < end:
                max_profit = max(max_profit,prices[end]-prices[start])
                start += 1
        
        return max_profit
        