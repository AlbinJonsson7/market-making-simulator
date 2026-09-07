#include "market/market_maker.hpp"
#include <cmath>



MarketMaker::MarketMaker(int64_t cash, int64_t quoteSpread, uint32_t orderSize, double inventorySkewFactor) : cash(cash), quoteSpread(quoteSpread), orderSize(orderSize), inventorySkewFactor(inventorySkewFactor){}


int64_t MarketMaker::calculateBidQuote(int64_t midPrice) const{
    auto skew = inventorySkewFactor * inventory;
    double reservationPrice = midPrice - skew;
    double theoreticalBid = reservationPrice - (static_cast<double>(quoteSpread) / 2.0);
    int64_t bidQuote = std::floor(theoreticalBid);
    return bidQuote;
}


int64_t MarketMaker::calculateAskQuote(int64_t midPrice) const{
    auto skew = inventorySkewFactor * inventory;
    double reservationPrice = midPrice - skew;
    double theoreticalAsk = reservationPrice + (static_cast<double>(quoteSpread) / 2.0);
    int64_t askQuote = std::ceil(theoreticalAsk);
    return askQuote;
}


void MarketMaker::recordBuyFill(int64_t price, uint32_t quantity){
    inventory += quantity;
    cash -= price * quantity;
}


void MarketMaker::recordSellFill(int64_t price, uint32_t quantity){
    inventory -= quantity;
    cash += price * quantity;
}


int64_t MarketMaker::getInventory() const{
    return inventory;
}


int64_t MarketMaker::getCash() const{
    return cash;
}


uint32_t MarketMaker::getOrderSize() const{
    return orderSize;
}





