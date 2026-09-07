#include "metrics/pnl_tracker.hpp"


PnLTracker::PnLTracker(int64_t initialCash) : initialCash(initialCash){}


int64_t PnLTracker::calculatePnL(int64_t cash, int64_t inventory, int64_t midPrice) const{
    return (getAccountValue(cash, inventory, midPrice) - initialCash);
}


int64_t PnLTracker::getAccountValue(int64_t cash, int64_t inventory, int64_t midPrice) const{
    return (cash + (inventory * midPrice));
}

