#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {

    int buy_in = prices[0];
    int profit = 0;

    for (int i = 1; i < pricesSize; i++) {

        int p = prices[i];

        if (buy_in > p) {
            buy_in = p;
        }

        if (p - buy_in > profit) {
            profit = p - buy_in;
        }
    }

    return profit;
}

//
// def maxProfit(prices: list[int]) -> int:
//     # 第一天開始買入
//     buy_in = prices[0]
//     # 初始化收入
//     profit = 0
//     # 買入的日期永遠比賣出小，所以可以忽略0
//     for p in prices[1::]:
//         # 讓 Price永遠保持最便宜
//         if buy_in > p:
//             buy_in = p
//         profit = max(profit, p - buy_in)
//         print(profit, p, buy_in)

//     return profit
//
