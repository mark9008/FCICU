#include "BankingApplication.h"

void BankingApplication::printMenu()
{
	while (1)
	{
		cout << "Welcome to FCI Banking Application and Information" << endl
			 << "  1. Create a New Account" << endl
			 << "  2. List Clients and Accounts" << endl
			 << "  3. Withdraw Money" << endl
			 << "  4. Deposit Money" << endl
			 << "  0. Exit!" << endl;
		int choice;
		cout << "Please Enter Choice =========> ";
		cin >> choice;
		if (choice == 1)
			createBankAccount();
		if (choice == 2)
		{
			for (int i = 0; i < BankAccounts.size(); i++)
			{
				cout << "-------------------------- " << clients[i]->getName() << " ---------------------------" << endl
					 << "Address: " << clients[i]->getAddress() << endl
					 << "Phone: " << clients[i]->getPhone() << endl
					 << "Account ID: " << BankAccounts[i]->getID();
				if (BankAccounts[i]->getType() == 1)
					cout << " (Basic)" << endl;
				else 
					cout << " (Saving)" << endl;
				cout << "Balance: " << BankAccounts[i]->getBalance() << endl;
				cout << "-------------------------------------------------------------------" << endl;
			}
		}
		if (choice == 3)
		{
			string id;
			cout << "Please Enter Account ID (e.g., FCI-015) =========> ";
			cin >> id;
			for (int i = 0; i < BankAccounts.size(); i++)
				if (BankAccounts[i]->getID() == id)
				{
					cout << "Account ID: " << BankAccounts[i]->getID() << endl;
					if (BankAccounts[i]->getType() == 1)
						cout << "Account Type: Basic" << endl;
					else 
						cout << "Account Type: Saving" << endl;
					cout << "Balance: " << BankAccounts[i]->getBalance() << endl;
					cout << "Please Enter The Amount to Withdraw =========> ";
					double amount;
					cin >> amount;
					BankAccounts[i]->withdraw(amount);
				}

		}
		if (choice == 4)
		{
			string id;
			cout << "Please Enter Account ID (e.g., FCI-015) =========> ";
			cin >> id;
			for (int i = 0; i < BankAccounts.size(); i++)
				if (BankAccounts[i]->getID() == id)
				{
					cout << "Account ID: " << BankAccounts[i]->getID() << endl;
					if (BankAccounts[i]->getType() == 1)
						cout << "Account Type: Basic" << endl;
					else 
						cout << "Account Type: Saving" << endl;
					cout << "Balance: " << BankAccounts[i]->getBalance() << endl;
					cout << "Please Enter The Amount to deposit =========> ";
					double amount;
					cin >> amount;
					BankAccounts[i]->deposit(amount);
				}
		}
		if (choice == 0)
		{
			break;
		}
		cout << "-------------------------------------------------------------------" << endl;
	}
}

void BankingApplication::createBankAccount()
{
	string n, ph, ad, id;
	double startingBalance;
	int type;
	cout << "\nPlease Enter Client Name =========> ";
	cin >> n;
	cout << "\nPlease Enter Client Address =======> ";
	cin >> ad;
	cout << "\nPlease Enter Client Phone =======> ";
	cin >> ph;
	cout << "\nWhat Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
	cin >> type;
	cout << "\nPlease Enter the Starting Balance =========> ";
	cin >> startingBalance;
	id = "FCI-";
	if (BankAccounts.size() < 9)
	{
		id += "00";
		id += to_string((long long)BankAccounts.size() + 1);
	}
	else if (BankAccounts.size() < 99)
	{
		id += "0";
		id += to_string((long long)BankAccounts.size() + 1);
	}
	else
	{
		id += to_string((long long)BankAccounts.size() + 1);
	}
	BankAccount* newBA;
	if (type == 1)
		newBA = new BankAccount(id,startingBalance);
	else
	{
		newBA = new SavingsBankAccount(id,startingBalance);
		if (startingBalance < 1000)
		{
			cout << "\nError! You Can't create a saving bank account with starting balance less than 1000" << endl;
			return;
		}
	}
	Client* newClient = new Client(n,ad,ph);
	newClient->setBA(newBA);
	BankAccounts.push_back(newBA);
	clients.push_back(newClient);
	cout << "\nAn account was created with ID " << id << " and Starting Balance " << startingBalance << " L.E." << endl;
}