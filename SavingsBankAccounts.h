#ifndef SAVINGSBANKACCOUNTS_H
#define SAVINGSBANKACCOUNTS_H
#include "BankAccounts.h"

class SavingsBankAccount : public BankAccount
{
private:
	double minimumBalance;
public:
	SavingsBankAccount(string id, double bal);
	void withdraw(double amount);
	void deposit(double amount);
};
#endif