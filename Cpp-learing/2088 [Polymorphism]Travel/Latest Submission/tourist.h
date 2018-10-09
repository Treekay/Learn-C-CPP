 #include "vehicle.h"
class Tourist {
 public:

    explicit Tourist(Vehicle* strategy_) : strategy(strategy_){}

    void setStrategy(Vehicle* strategy_){
    	strategy = strategy_;
    }

    void travel(const City& src, const City& dest){
    	strategy->doTravel(src, dest);
    }

 private:
    Vehicle* strategy;
};
