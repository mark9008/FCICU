#include "BankAccounts.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


BankAccount::BankAccount()
{
	ID = "";
	balance = 0;
	type = 1;
}

BankAccount::BankAccount(string id, double bal)
{
	ID = id;
	balance = bal;
	type = 1;
}

void BankAccount::setID(string id)
{
	ID = id;
}

void BankAccount::setBalance(double bal)
{
	balance = bal;
}

string BankAccount::getID()
{
	return ID;
}

double BankAccount::getBalance()
{
	return balance;
}

int BankAccount::getType()
{
	return type;
}

void BankAccount::withdraw(double amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		cout << "The amount of: " << amount << " has been withdrawed successfully from your account!\nNew Balance: " << balance << endl;
	}
	else
		cout << "Error! The amount you want to withdraw is less than the account balance which is: " << balance << endl;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
	cout << "The amount of: " << amount << " has been deposited successfully into your account!\nNew Balance: " << balance << endl;
}