/**
 * You are given a list of stock prices, where `prices[i]` represents the price of a stock on day *i*.
 * Your task is to find the maximum profit you can make by:
 *
 * Buying on one day, and
 * Selling on a later day (index must be larger).
 *
 * If you cannot make any profit, you must return 0.
 * Input
 * A list of integers, for example:
 * [7, 1, 5, 3, 6, 4]
 * Output:
 * A single integer representing the maximum possible profit, for example: 5
 *
 * Two possible outcomes:
 *
 * 1. If there exists a profitable transaction → return the maximum profit
 * Example:
 * Input:  [7,1,5,3,6,4]
 * Output: 5
 * Buy at 1, sell at 6 → profit = 6 − 1 = 5
 *
 * 2. If no profitable transaction exists → return 0
 * Example:
 * Input:  [7,6,4,3,1]
 * Output: 0
 * Prices only go down → no profit possible.
 *
 * ✔️ Summary:
 * If you can make a profit, return the maximum profit.
 * If not, return 0.
**/

#pragma once
#include <vector>

template<typename T>
class StockProfit {
public:
    T maxProfit(const std::vector<T>& prices);
};

