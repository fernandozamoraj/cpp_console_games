#ifndef SLOT_MACHINE_PURSE_HPP
#define SLOT_MACHINE_PURSE_HPP
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Purse{

private: 
    vector<string> ledger;
    double totalAdds;
    double totalBets;
    double totalWins;
    double totalWithdrawals;
public:
    Purse(){
       totalAdds = 0.0;
       totalBets = 0.0;
       totalWins = 0.0;
       totalWithdrawals = 0.0;
    }

    Purse(const Purse &other){
       totalAdds = other.totalAdds;
       totalBets = other.totalBets;
       totalWins = other.totalWins;
       ledger.clear();
       for(auto s: other.ledger){
          ledger.push_back(s);
       }
    }

    Purse operator=(const Purse &other){
       totalAdds = other.totalAdds;
       totalBets = other.totalBets;
       totalWins = other.totalWins;
       ledger.clear();
       for(auto s: other.ledger){
          ledger.push_back(s);
       }

       return *this;
    }

    double getBalance() const{
       return totalAdds - totalBets + totalWins - totalWithdrawals;
    }

    double bet(double amount){
        if(getBalance() >= amount){
           
            stringstream ss;
            ss << "You bet " << amount;
            ledger.push_back(ss.str());

            totalBets += amount;
            return amount;
        }
        else{
            stringstream ss;
            ss << "Bet in the amount " << amount << " failed.";
            ledger.push_back(ss.str());
        }

          
        return 0.0;
    }

    double collectWin(double amount){
       totalWins += amount;
       
       stringstream ss;
       ss << "You won " << amount;
       ledger.push_back(ss.str());
    }

    double addMoney(double amount){
        totalAdds += amount;

        stringstream ss;
        ss << "You added " << amount << " New Balance " << getBalance();
        ledger.push_back(ss.str());
    }

    double cashOut(){
        double amount = getBalance();

        totalWithdrawals += amount;

        stringstream ss;
        ss << "You cashed out " << amount << " New Balance " << getBalance();

        return amount;
    }

    void clear(){
        stringstream ss;
        ss << "Ledger was cleared of  " << getBalance();

        totalAdds = 0;
        totalBets = 0;
        totalWins = 0;
        totalWithdrawals = 0;

        ledger.push_back(ss.str());
    }

    string dumpPurseLedger(){
       stringstream ss;

       ss << "Total Adds: " << totalAdds << endl;
       ss << "Total Bets: " << totalBets << endl;
       ss << "Total Wins: " << totalWins << endl;
       ss << "Total Withdrawals: " << totalWithdrawals << endl;
       for(auto line: ledger){
           ss << line << endl;
       }

       ss << endl;

       return ss.str();
    }
};


#endif