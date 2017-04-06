#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

//   Mahmudul   Hasan   Khan   CE09003

namespace AccountNamespace {

	class Account {

		char accNo[100];
		double balance;

	public:

		Account() {
			balance = 0.0000;
			cout<<"\n\tBase Constructor has been called . ";
		}

		Account(char* accNo) {
			Account();
			strcpy(this->accNo,accNo);
			balance = 0.0000;
		}

		char* getAccNo() {
			return accNo;
		}

		double getBalance() {
			return balance;
		}

		char* deposit(double amount) {
			balance += amount;
			return "\n\tDeposited successfully .";
		}

		virtual char* withDraw(double amount) {
			balance -= amount;
			return "\n\tWithdrawn successfully .";
		}

		char* aNonVirtualMethod() {
			return "\n\tFrom base Account about nonVirtualMethod() .";
		}

	};

	class SavingsAccount : public Account {

		double interestAmount;

	public:

		SavingsAccount(char* accNo, double interestAmount) : Account(accNo) {
			this->interestAmount = interestAmount;
			cout<<"\n\tSavings Consturctor has been called .";
		}

		char* withDraw(double amount) {
			if((getBalance()-amount)>=1000) {
				return Account::withDraw(amount);
			}

			return "\n\tUnderflow !!! Insufficient Balance .";
		}

		double getInterestAmount() {
			return interestAmount;
		}

		char* aNonVirtualMethod() {
			return "\n\tFrom SavingsAccount about nonVirtualMethod() .";
		}

	};

	class CheckingAccount : public Account {

		int noOfTranscations;
		double serviceCharge;

	public:

		CheckingAccount(char* accNo, double serviceCharge) : Account(accNo) {
			this->serviceCharge = serviceCharge;
			noOfTranscations = 0;
			cout<<"\n\tChecking Consturctor has been called .";
		}

		double getNoOfTranscations() {
			return noOfTranscations;
		}

	};

}

void show_Transactions(AccountNamespace::Account **accounts, int totalNoOfAccounts) {
	for (int i = 0; i < totalNoOfAccounts; i++)
	{
		cout<<"\n"<<accounts[i]->deposit(5000);
		cout<<"\tAccount No. "<<accounts[i]->getAccNo()<<"\tBalance : "<<accounts[i]->getBalance();
		cout<<accounts[i]->withDraw(1000);
		cout<<"\tAccount No. "<<accounts[i]->getAccNo()<<"\tBalance : "<<accounts[i]->getBalance();
		cout<<accounts[i]->withDraw(10000);
		cout<<"\n\tAccount No. "<<accounts[i]->getAccNo()<<"\tBalance : "<<accounts[i]->getBalance();
	}
}

int main() {

	using namespace AccountNamespace;
	cout<<"\n\n\n\tStaring CPPInheritanceAccApp1 ..... ";

	int totalNoOfAccounts = 0;

	SavingsAccount *aSavingsAccount = new SavingsAccount("SV:001",4500);
	totalNoOfAccounts++;
	CheckingAccount *aCheckingAccount = new CheckingAccount("CK:001",2500);
	totalNoOfAccounts++;

	Account **accounts = new Account*[1000];
	accounts[0] = aSavingsAccount;
	accounts[1] = aCheckingAccount;
	accounts[2] = new Account("CK:002");
	totalNoOfAccounts++;

	show_Transactions(accounts,totalNoOfAccounts);

	cout<<"\n"<<accounts[0]->aNonVirtualMethod();
	cout<<aSavingsAccount->aNonVirtualMethod();

	delete accounts[2];
	delete[] accounts;
	delete aSavingsAccount;
	delete aCheckingAccount;
	getch();

	return 0;

}
