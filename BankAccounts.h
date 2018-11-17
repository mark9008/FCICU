#ifndef BANKACCOUNTS_H
#define BANKACCOUNTS_H
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class BankAccount
{
protected:
	string ID;
	double balance;
	int type;
public:
	BankAccount();
	BankAccount(string id, double bal);
	void setID(string id);
	void setBalance(double bal);
	string getID();
	double getBalance();
	int getType();
	virtual void withdraw(double amount);
	virtual void deposit(double amount);
};
#endif