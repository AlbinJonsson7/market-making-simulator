#include <iostream>

#include "market/market.hpp"
#include "market/market_maker.hpp"
#include "market/fill_model.hpp"
#include "metrics/pnl_tracker.hpp"

int main(){
    Market market(
        10000,   // mid price
        4,       // market spread
        3.0,     // volatility
        42       // seed
    );

    MarketMaker marketMaker(
        1000000, // initial cash
        4,       // quote spread
        10       // order size
    );

    FillModel fillModel(
        0.30,    // buy fill probability
        0.30,    // sell fill probability
        73       // seed
    );

    PnLTracker pnlTracker(
        1000000 // initial cash
    );

    const int simulationSteps = 20;

    for (int step = 0; step < simulationSteps; ++step)
    {
        int64_t midPrice = market.getMidPrice();
        int64_t marketBid = market.getBestBid();
        int64_t marketAsk = market.getBestAsk();

        int64_t ourBid = marketMaker.calculateBidQuote(midPrice);
        int64_t ourAsk = marketMaker.calculateAskQuote(midPrice);

        bool buyFilled =
            fillModel.shouldFillBuy(ourBid, marketBid);

        bool sellFilled =
            fillModel.shouldFillSell(ourAsk, marketAsk);

        if (buyFilled)
        {
            marketMaker.recordBuyFill(
                ourBid,
                marketMaker.getOrderSize()
            );
        }

        if (sellFilled)
        {
            marketMaker.recordSellFill(
                ourAsk,
                marketMaker.getOrderSize()
            );
        }

        int64_t inventory = marketMaker.getInventory();
        int64_t cash = marketMaker.getCash();

        std::cout
            << "Step: " << step
            << " | Mid: " << midPrice
            << " | Market: " << marketBid << "/" << marketAsk
            << " | Quotes: " << ourBid << "/" << ourAsk
            << " | BuyFill: " << buyFilled
            << " | SellFill: " << sellFilled
            << " | Inventory: " << inventory
            << " | Cash: " << cash
            << " | AccountValue: " << pnlTracker.getAccountValue(cash, inventory, midPrice)
            << " | PnL: " << pnlTracker.calculatePnL(cash, inventory, midPrice)
            << '\n';

        market.updatePrice();
    }


    return 0;
}