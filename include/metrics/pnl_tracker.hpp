#ifndef PNL_TRACKER_HPP
#define PNL_TRACKER_HPP


#include <cstdint>


class PnLTracker{
    private:
        int64_t initialCash;

    public:
        PnLTracker(int64_t initialCash);
        int64_t calculatePnL(int64_t cash, int64_t inventory, int64_t midPrice) const;
        int64_t getAccountValue(int64_t cash, int64_t inventory, int64_t midPrice) const;

};

#endif // PNL_TRACKER_HPP