//
//  main.cpp
//  strategy_simulation
//
//  Created by Mahmoud Chahine on 9/23/22.
//

#include <iostream>
#include <chrono> //For system_clock
#include <random>
#include <iomanip>
#include "Account.hpp"//;
using namespace std;
Account set_account();

int main(int argc, const char * argv[]) {
    // insert code here...
    double account_balance=20, profit_percent=0, loss_percent=0;
    Account account=set_account();
    cout<<account.get_balance();
    //So now I have to create a function on the account for a strategy
    //Will go through a loop of the total trades random buys, wins, but buys will look for a fixed percent
    //it must keep track of how many times I win or lose in a row
    //if I lose 4 times in a row will reduce the loss percent by half and win percent reduce it by 25 percent if I win 2 times in a row will go back to the original target
    cout << "Hello, World!\n";
    return 0;
}
Account set_account()
{
    double balance=0, profit_percent=0, loss_percent=0;
    int trades_taken=0;
    Account account=*new Account();
    cout<<"Enter your account balance: ";
    cin>>balance;
    cout<<endl;
    cout<<"Enter your profit percent: ";
    cin>>profit_percent;
    cout<<endl;
    cout<<"Enter your loss percent: ";
    cin>>loss_percent;
    cout<<endl;
    cout<<"Enter total trades: ";
    cin>>trades_taken;
    account.set_balance(balance);
    account.set_loss_percent(loss_percent);
    account.set_profit_percent(profit_percent);
    account.set_trades_taken(trades_taken);
    return account;
}
