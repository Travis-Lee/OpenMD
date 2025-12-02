#include "best_time_to_buy_and_sell_stock.h"

template<typename T>
T StockProfit<T>::maxProfit(const std::vector<T>& prices) {
    if (prices.empty()) {
        return 0; // No prices available
    }
    T min_price = prices[0]; // Initialize min_price to the first day's price
    T max_profit = 0;       // Initialize max_profit to zero    

    for (const T& price : prices) {
        if (price < min_price) {
            min_price = price; // Update min_price if a lower price is found
        } else {
            T potential_profit = price - min_price; // Calculate potential profit
            if (potential_profit > max_profit) {
                max_profit = potential_profit; // Update max_profit if the potential profit is higher
            }
        }
    }
    return max_profit; // Return the maximum profit found
}

template class StockProfit<int>;