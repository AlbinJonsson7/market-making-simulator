#ifndef FILL_MODEL_HPP
#define FILL_MODEL_HPP

#include <cstdint>
#include <random>

class FillModel{
    private:
        double buyFillProbability;
        double sellFillProbability;
        std::mt19937 randomEngine;
        std::uniform_real_distribution<double> fillDistribution;
    public:
        FillModel(double buyFillProbability, double sellFillProbability, uint32_t seed);
        bool shouldFillBuy(int64_t ourBid, int64_t marketBestBid);
        bool shouldFillSell(int64_t ourAsk, int64_t marketBestAsk);   

};



#endif // FILL_MODEL_HPP