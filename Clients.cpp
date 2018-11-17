#include "Clients.h"

Client::Client(string n, string ad, string ph)
{
	name = n;
	address = ad;
	phone = ph;
	bankAccount = new BankAccount();
}

void Client::setBA(BankAccount* BA)
{
	this->bankAccount = BA;
}

BankAccount* Client::getBA()
{
	return this->bankAccount;
}

string Client::getName()
{
	return name;
}

string Client::getAddress()
{
	return address;
}

string Client::getPhone()
{
	return phone;
}