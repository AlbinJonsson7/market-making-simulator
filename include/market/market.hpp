#ifndef MARKET_HPP
#define MARKET_HPP

#include <cstdint>
#include <random>

class Market{
    private:
        int64_t midPrice;
        int64_t spread;
        double volatility;
        std::mt19937 randomEngine;
        std::normal_distribution<double> priceDistribution;


    public:
        Market(int64_t midPrice, int64_t spread, double volatility, uint32_t seed);
        int64_t getMidPrice() const;
        int64_t getBestBid() const;
        int64_t getBestAsk() const;
        void updatePrice();

};

#endif // MARKET_HPP