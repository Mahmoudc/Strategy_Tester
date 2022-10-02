//
//  Account.cpp
//  strategy_simulation
//
//  Created by Mahmoud Chahine on 9/23/22.
//
using namespace std;
#include "Account.hpp"
#include <iostream>
#include <chrono> //For system_clock
#include <random>
#include <iomanip>
#include <fstream>

Account::Account(double balance, double profit_percent, double loss_percent)
{
    this->balance=balance;
    this->profit_percent=profit_percent;
    this->loss_percent=loss_percent;
}
Account::Account()
{
    this->balance=original_balance;
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
    this->original_balance=balance;
}
void Account::set_profit_percent(double p)
{
    this->profit_percent=p;
    original_profit_percent=profit_percent;
}
void Account::set_loss_percent(double l)
{
    this->loss_percent=l;
    original_loss_percent=loss_percent;
}
void Account::strategy_1(int runs)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distributionInteger(0, 1);
    int random_trade=0;
    int wins=0, losses=0, break_even=0;
    int row_track=0;
    fstream file;
    file.open("test.txt",std::ios::out);
    file << "fflush";
    file.close();
    for(int i=0;i<trades_taken;i++)
    {
        srand(seed);
        random_trade=distributionInteger(generator);
        switch(random_trade)
        {
            case 0:
                wins++;
                this->balance+=((this->profit_percent/100.0)*this->original_balance);
                row_track++;
                cout<<i+1<<"- Win percent: +"<<profit_percent<<"%"<<endl;
                cout<<"Current balance: $"<<balance<<endl;
                cout<<"Row track: "<<row_track<<endl<<endl;
                break;
            case 1:
                losses++;
                this->balance-=((this->loss_percent/100.0)*this->original_balance);//the loss must be base on the original balance
                row_track--;
                cout<<i+1<<"- Loss percent: -"<<loss_percent<<"%"<<endl;
                cout<<"Current balance: $"<<balance<<endl;
                cout<<"Row track: "<<row_track<<endl<<endl;
                break;
//            case 2:
//                break_even++;
//                break;
                
        }
       // cout<<"Current balance: $"<<balance<<endl;
        double profit_times_3=(original_balance*(profit_percent/100.0)*3)+original_balance;
        double loss_times_4=(original_balance*(loss_percent/100.0)*4)-original_balance;
        //The issue is that your adjusting the original balance so the original data is lost
        if(row_track==2) //check that its 4 times profit from the original balance as well
        {
            //increase stop loss and profit double
            //will reset the row track as well
            this->profit_percent=original_profit_percent*2;
            this->loss_percent=original_loss_percent*2;
            row_track=0;
            //What if it was a 4 but then went back down to like 2 losses in a row we'll have to reduce by half again
        }
        //So we need to get back to the original state when I condition is meet
        //Lose twice in a row go back to original state
        else if(row_track==-2 || row_track==0)
        {
            this->profit_percent=original_profit_percent;
            this->loss_percent=original_loss_percent;
            //row_track=0;
        }
        else if(row_track==-4)
        {
            //profit will decrease by 10% and loss will decrease by 30%
            profit_percent=(original_profit_percent*0.90);
            loss_percent=(original_loss_percent*0.70);
            row_track=0;
        }
    
        //Now if I win like 3 times in a row stop loss will be doubled and win rate will be doubled
        //If I lose when I got to 3 times in a row once go back to original state
        //If I go below account balance 4 times in a row
        //so now if the trade is
    }
    total_profit=((balance-original_balance)/original_balance)*100;
    cout<<endl<<endl;
    cout<<runs<<"- "<<"Your total wins is: "<<wins<<endl<<"Your total losses is: "<<losses<<endl;
  //  cout<<"Your total break even is: "<<break_even<<endl;
    cout<<"Win rate percent: "<<fixed<<setprecision(2)<<((double)wins/trades_taken)*100.0<<"%"<<endl;
    cout<<"Profit percent: "<<total_profit<<"%";
    cout<<endl;
    //double profit_account=(total_profit/100)*account_balance;
    cout<<"Account balance: $"<<fixed<<setprecision(2)<<balance<<endl;
    cout<<"Profit on account balance: $"<<fixed<<setprecision(2)<<balance-original_balance<<endl;
    cout<<"Your profit share for prop firm account: $"<<fixed<<setprecision(2)<<(balance-original_balance)*0.80<<endl<<endl;
    balance=original_balance;
    //reset the win and loss percentages
    profit_percent=original_profit_percent;
    loss_percent=original_loss_percent;
    if(total_profit>0)
    {
        total_win_count++;
    }
    
}
void Account::display_total_win_rate(int r)
{
    //r
    double win_rate=((double)total_win_count/r)*100;
    cout<<"\nYour total win rate is: "<<win_rate<<"%"<<endl;
    total_win_count=0;
}

void Account::find_rr_percent_symbol()
{
    int select_value=0;
    double points=0;
    double risk_percent=0;
    double lot_size=0.01;
    do
    {
        cout<<"Select a symbol:"<<endl;
        cout<<"1- XAUUSD\n2- NAS100\n3- US30\n4- EURUSD\n5- GBPUSD"<<endl;
        cin>>select_value;
        cout<<"\nEnter your risk percent: ";
        cin>>risk_percent;
        cout<<"\nEnter lot size: ";
        cin>>lot_size;
    }while(select_value<1&&select_value>5);
    if(select_value==1)
    {
        //So if 1% means 1 dollar
        //that means 0.01 is 0.01
        //0.10 is
        if(lot_size<1)
            points=((double)risk_percent)*(1.0/lot_size);
        else if(lot_size>=1)
            points=((double)risk_percent)*lot_size;
        cout<<"\nPoints equivalent: "<<points<<endl;
    }
}
