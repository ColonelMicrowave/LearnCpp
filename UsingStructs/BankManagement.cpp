#include <iostream>
#include <string>
#include <limits>

struct BankAccount
{
	enum Type
	{
		Checkings,
		Savings,
	};

	Type accountType{ Checkings };
	std::string name{ "John" };
	int accountNumber{ 0 };
	double balance{ 2000.00 };

	bool checkAccountNumber(int accountNumberInput) const
	{
		return (accountNumber == accountNumberInput);
	}

	void deposit(double amount)
	{
		std::cout << "Depositing $" << amount << " into account...\n";
		balance += amount;
	}

	void withdraw(double amount)
	{
		std::cout << "Withdrawing $" << amount << " from account...\n";
		balance -= amount;
	}
};

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getUserChoice()
{
	std::cout << "1. Create account\n";
	std::cout << "2. Deposit\n";
	std::cout << "3. Withdraw\n";
	std::cout << "4. Check details\n";

	while (true)
	{
		std::cout << "Enter your choice: ";
		int choice{};
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else if (choice < 1 || choice > 4)
		{
			ignoreLine();
			std::cout << "Invalid choice. Please try again.\n";
		}
		else
		{
			ignoreLine();
			std::cout << '\n';
			return choice;
		}
	}
}

void createAccount(BankAccount& account, bool& loggedIn)
{
	std::string accountType{};

	while (true)
	{
		std::cout << "Enter account type (checkings or savings): ";
		std::cin >> accountType;

		if (accountType == "checkings" || accountType == "Checkings")
		{
			ignoreLine();
			account.accountType = BankAccount::Checkings;
		}
		else if (accountType == "savings" || accountType == "Savings")
		{
			ignoreLine();
			account.accountType = BankAccount::Savings;
		}
		else
		{
			ignoreLine();
			std::cout << "Invalid account type. Please try again.\n";
			continue;
		}

		std::cout << "Enter your first name: ";
		std::cin >> account.name;

		std::cout << "Enter account number: ";
		std::cin >> account.accountNumber;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else
		{
			ignoreLine();
			std::cout << "Account created successfully. You are now logged in.\n";
			loggedIn = true;
			break;
		}
	}
}

void displayAccountDetails(const BankAccount& account)
{
	std::cout << "Account Holder: " << account.name << '\n';
	std::cout << "Account Number: " << account.accountNumber << '\n';
	std::cout << "Account Type: " << (account.accountType == BankAccount::Checkings ? "Checkings" : "Savings") << '\n';
}

void deposit(BankAccount& account)
{
	while (true)
	{
		std::cout << "Enter amount to deposit: ";
		double amount{};
		std::cin >> amount;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else if (amount < 0)
		{
			ignoreLine();
			std::cout << "Invalid amount. Please try again.\n";
		}
		else
		{
			ignoreLine();
			account.deposit(amount);
			break;
		}
	}
}

void withdraw(BankAccount& account)
{
	while (true)
	{
		std::cout << "Enter amount to withdraw: ";
		double amount{};
		std::cin >> amount;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else if (amount < 0)
		{
			ignoreLine();
			std::cout << "Invalid amount. Please try again.\n";
		}
		else if (amount > account.balance)
		{
			ignoreLine();
			std::cout << "Insufficient funds. Please try again.\n";
		}
		else
		{
			ignoreLine();
			account.withdraw(amount);
			break;
		}
	}
}

void checkDetails(const BankAccount& account)
{
	displayAccountDetails(account);
	std::cout << "Account balance: $" << account.balance << '\n';
}

bool loginToAccount(const BankAccount& account)
{
	while (true)
	{
		std::cout << "Verify your account number to login (enter 0 if you have no account): ";
		int accountNumber{};
		std::cin >> accountNumber;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else if (account.checkAccountNumber(accountNumber))
		{
			ignoreLine();
			return true;
		}
		else
		{
			ignoreLine();
			std::cout << "Invalid account number. Please try again.\n";
		}
	}
}

void readUserInput(BankAccount& account, bool& loggedIn)
{
	int choice{ getUserChoice() };

	if ((loggedIn) && (choice != 1))
	{
		switch (choice)
		{
		case 2:
			deposit(account);
			break;
		case 3:
			withdraw(account);
			break;
		case 4:
			checkDetails(account);
			break;
		}
	}
	else if (choice == 1)
	{
		createAccount(account, loggedIn);
	}
	else
	{
		std::cout << "You must login to perform any action.\n";
		loggedIn = loginToAccount(account);
	}
}

bool takeAnotherAction()
{
	while (true)
	{
		std::cout << "\nWould you like to perform another action? (y/n): ";
		char choice{};
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else if (choice == 'y' || choice == 'Y')
		{
			ignoreLine();
			return true;
		}
		else if (choice == 'n' || choice == 'N')
		{
			ignoreLine();
			return false;
		}
		else
		{
			ignoreLine();
			std::cout << "Invalid choice. Please try again.\n";
		}
	}
}

int main()
{
	BankAccount account{};
	bool isLoggedIn{ false };

	while (true)
	{
		readUserInput(account, isLoggedIn);

		if (!takeAnotherAction())
			return 0;

		std::cout << '\n';
	}
}
