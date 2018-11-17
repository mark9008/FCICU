#include "SavingsBankAccounts.h"

SavingsBankAccount::SavingsBankAccount(string id, double bal) : BankAccount(id, bal)
{
	minimumBalance = 1000;
	type = 2;
}

void SavingsBankAccount::withdraw(double amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		if (balance < minimumBalance)
		{
			balance += amount;
			cout << "Sorry you can't withdraw this amount: " << amount << " because the new balance will be less than " << minimumBalance << endl;
		}
		else
			cout << "The amount of: " << amount << " has been withdrawed successfully from your account!\nNew Balance: " << balance << endl;
	}
	else
		cout << "Error! The amount you want to withdraw is less than the account balance which is: " << balance << endl;
}

void SavingsBankAccount::deposit(double amount)
{
	if (amount >= 100)
	{
		balance += amount;
		cout << "The amount of: " << amount << " has been deposited successfully into your account!\nNew Balance: " << balance << endl;
	}
	else 
		cout << "Sorry you can't deposit an amount less than 100!" << endl;
}