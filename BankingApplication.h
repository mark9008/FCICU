#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H
#include "BankAccounts.h"
#include "Clients.h"
#include "SavingsBankAccounts.h"

class BankingApplication 
{
private:
	vector<BankAccount*> BankAccounts;
	vector<Client*> clients;
public:
	void printMenu();
	void createBankAccount();
};

#endif