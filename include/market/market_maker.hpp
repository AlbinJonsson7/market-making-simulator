#ifndef MARKET_MAKER_HPP
#define MARKET_MAKER_HPP


#include <cstdint>


class MarketMaker{
    private:
        int64_t inventory = 0;
        int64_t cash;
        int32_t quoteSpread;
        uint32_t orderSize;

    public: 
        MarketMaker(int64_t cash, int64_t quoteSpread, uint32_t orderSize);

        int64_t calculateBidQuote(int64_t midPrice) const;
        int64_t calculateAskQuote(int64_t midPrice) const;

        void recordBuyFill(int64_t price, uint32_t quantity);
        void recordSellFill(int64_t price, uint32_t quantity);

        int64_t getInventory() const;
        int64_t getCash() const;
        uint32_t getOrderSize() const;
};


#endif // MARKET_MAKER_HPP