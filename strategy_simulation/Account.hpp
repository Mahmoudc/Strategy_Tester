//
//  Account.hpp
//  strategy_simulation
//
//  Created by Mahmoud Chahine on 9/23/22.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#endif /* Account_hpp */

class Account {
private:
    double original_balance=0;
    double original_profit_percent=0;
    double original_loss_percent=0;
    double balance=0;
    double profit_percent=0;
    double loss_percent=0;
    double total_profit=0;
    int trades_taken=0;
public:
    Account(double balance, double profit_percent, double loss_percent);
    Account();
    int get_trades_taken();
    double get_balance();
    double get_profit_percent();
    double get_loss_percent();
    void set_balance(double b);
    void set_trades_taken(int);
    void set_profit_percent(double p);
    void set_loss_percent(double l);
    void strategy_1(int r);
};
