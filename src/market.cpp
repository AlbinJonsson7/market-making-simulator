#include "market/market.hpp"
#include <cmath>




Market::Market(int64_t midPrice, int64_t spread, double volatility, uint32_t seed) : midPrice(midPrice), spread(spread), volatility(volatility), randomEngine(seed), priceDistribution(0,volatility){}


int64_t Market::getMidPrice() const{
    return midPrice; 
}


int64_t Market::getBestBid() const{
    auto bestBid = midPrice - (spread/2);
    return bestBid;
}


int64_t Market::getBestAsk() const{
    auto bestAsk = midPrice + (spread/2);
    return bestAsk;
}


void Market::updatePrice(){

    double randomMove = priceDistribution(randomEngine);
    int64_t tickMove = std::round(randomMove);
    midPrice += tickMove;

}


