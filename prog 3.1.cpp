#include <iostream>
#include <string>
using namespace std ;
class BankAccount
{
    private:
    //Data members
    string owner;
    double balance;
    public;
    //Member function to open account
    void openAccount(string name , double initial)
    {
        owner= name;
        if (initial>0)
        balance= initial;
        else
        balance = 0;

    }
    //Member function to deposit money
    void deposit (double amount)
    {
        if (amount>0)
        balance= balance + amount;

    }
    bool withdraw (double amount)
    {
        if (amount>0 && amount<=balance)
        {
            balance = balance-amount;
            return true;
        
        }
        return false;
    }
    //Getter function
    string getOwner()
    {
        return owner;
    }
    //Get
    double getbalance()
    {
        return balance;

    }
    int main()
    {
        Bank Account Account ;
string name;
double initialdeposit;
double depositamount;
double depositwithdrawl;
//Account holder name
cout<< "enter account holder name :";
getline(cin,name);
// initial deposit
cout<<"enter amount to deposit:";
cin>>depositamount;

    }
