# Time Limit Exceeded
def maxProfit(prices: list[int]) -> int:
    profit = 0
    for i in range(len(prices)):
        for j in range(len(prices)):
            if i > j and prices[i] != prices[j]:
                profit == 0
            elif i < j and prices[i] != prices[j]:
                p = prices[j] - prices[i]
                if p > profit:
                    profit = p
    return profit
# solution 2
# i = buy in
# j = sold
# j always > i
# Time Limit Exceeded
def maxProfit(prices: list[int]) -> int:
    profit = 0
    for i in range(len(prices)):
        for j in range(i + 1, len(prices)):
            p = prices[j] - prices[i]
            if p > profit:
                  profit = p

    return profit


# solution 3
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/5501275/video-keep-minimum-price-solution-by-nii-s09f
def maxProfit(prices: list[int]) -> int:
    # 第一天開始買入
    buy_in = prices[0]
    # 初始化收入
    profit = 0
    # 買入的日期永遠比賣出小，所以可以忽略0
    for p in prices[1::]:
        # 讓 Price永遠保持最便宜
        if buy_in > p:
            buy_in = p
        profit = max(profit, p - buy_in)
        print(profit, p, buy_in)

    return profit

profit = maxProfit(prices=[7,1,5,3,6,4])

#LeetCode #1929 Concatenation of Array
#LeetCode #1480 Running Sum of 1d Array
#LeetCode #121 Best Time to Buy and Sell Stock
#LeetCode #1 Two Sum