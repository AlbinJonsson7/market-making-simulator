#include "market/market_maker.hpp"



MarketMaker::MarketMaker(int64_t cash, int64_t quoteSpread, uint32_t orderSize) : cash(cash), quoteSpread(quoteSpread), orderSize(orderSize){}


int64_t MarketMaker::calculateBidQuote(int64_t midPrice) const{
    auto bidQuote = midPrice - (quoteSpread/2);
    return bidQuote;
}


int64_t MarketMaker::calculateAskQuote(int64_t midPrice) const{
    auto askQuote = midPrice + (quoteSpread/2);
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





