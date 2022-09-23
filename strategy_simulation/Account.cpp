//
//  Account.cpp
//  strategy_simulation
//
//  Created by Mahmoud Chahine on 9/23/22.
//

#include "Account.hpp"

Account::Account(double balance, double profit_percent, double loss_percent)
{
    this->balance=balance;
    this->profit_percent=profit_percent;
    this->loss_percent=loss_percent;
}
Account::Account()
{
}
double Account::get_balance() {
    return this->balance;
}
double Account::get_profit_percent() {
    return this->profit_percent;
}
double Account::get_loss_percent() {
    return this->loss_percent;
}
int Account::get_trades_taken() {
    return this->trades_taken;
}
void Account::set_trades_taken(int t)
{
    this->trades_taken=t;
}
void Account::set_balance(double b)
{
    this->balance=b;
}
void Account::set_profit_percent(double p)
{
    this->profit_percent=p;
}
void Account::set_loss_percent(double l)
{
    this->loss_percent=l;
}
