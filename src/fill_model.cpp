#include "market/fill_model.hpp"


FillModel::FillModel(double buyFillProbability, double sellFillProbability, uint32_t seed) : buyFillProbability(buyFillProbability), sellFillProbability(sellFillProbability), randomEngine(seed), fillDistribution(0,1){}
        

bool FillModel::shouldFillBuy(int64_t ourBid, int64_t marketBestBid){
    if(ourBid < marketBestBid){
        return false;
    }

    double randomNumber = fillDistribution(randomEngine);

    if(randomNumber < buyFillProbability){
        return true;
    }

    return false;
}


bool FillModel::shouldFillSell(int64_t ourAsk, int64_t marketBestAsk){
    if(ourAsk > marketBestAsk){
        return false;
    }

    double randomNumber = fillDistribution(randomEngine);

    if(randomNumber < sellFillProbability){
        return true;
    }

    return false;
}   


