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
Account set_account(double b=0);

int main(int argc, const char * argv[]) {
    // insert code here..
    int runs=0;
    int program_type=0;
    Account account=*new Account();
    while(true)
    {
        cout<<"Enter the program you'd like to run"<<endl;
        cout<<"1- For strategy simulation\n2- To find points per trade\n";
        cin>>program_type;
        if(program_type==1)
        {
            Account account=set_account(account.get_balance());
            cout<<"\nEnter how many times you would like to run simulations: ";
            cin>>runs;
            for(int i=0;i<runs;i++)
            {
                account.strategy_1(i+1);
            }
            account.display_total_win_rate(runs);
        }
        else if(program_type==2)
        {
            Account::find_rr_percent_symbol();
        }
        
    }
    
    
    //cout<<account.get_balance();
    //So now I have to create a function on the account for a strategy
    //Will go through a loop of the total trades random buys, wins, but buys will look for a fixed percent
    //it must keep track of how many times I win or lose in a row
    //if I lose 4 times in a row will reduce the loss percent by half and win percent reduce it by 25 percent if I win 2 times in a row will go back to the original target
    //cout << "Hello, World!\n";
    return 0;
}
Account set_account(double b)
{
    double balance=0, profit_percent=0, loss_percent=0, total_profit=0;
    int trades_taken=0;
    Account account=*new Account();
    if(b==0)
    {
        cout<<"Enter your account balance: ";
        cin>>balance;
        b=balance;
    }
    
    
    cout<<endl;
    cout<<"Enter your profit percent: ";
    cin>>profit_percent;
    cout<<endl;
    cout<<"Enter your loss percent: ";
    cin>>loss_percent;
    cout<<endl;
    cout<<"Enter total trades: ";
    cin>>trades_taken;
    account.set_balance(b);
    account.set_loss_percent(loss_percent);
    account.set_profit_percent(profit_percent);
    account.set_trades_taken(trades_taken);
    return account;
}
