#ifndef CLIENTS_H
#define CLIENTS_H
#include "BankAccounts.h"

class Client 
{
private:
	string name;
	string address;
	string phone;
	BankAccount* bankAccount;
public:
	Client();
	Client(string n, string ad, string ph);
	void setBA(BankAccount*);
	string getName();
	string getAddress();
	string getPhone();
	BankAccount* getBA();
};
#endif