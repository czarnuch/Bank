#include "brass.h"
#include<string>
#include<iostream>
using std::cout;
using std::cin;



Brass::Brass(const std::string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		std::cout << "Nie mo¿esz wplaciæ ujemnej kwoty\n";
	else
		balance += amt;

}

void Brass::Withdraw(double amt)
{
	if (balance <= amt)
		std::cout << "Nie masz wystarczajacych srodkow, dowidzenia";
	else
		balance -= amt;
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	std::cout << "Imie i Nazwisko: " << fullName << std::endl;

	std::cout << "Nr rachunku: " << acctNum << std::endl;

	std::cout << "Stan konta: " << balance << std::endl;

}

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r) : Brass(s, an, bal), maxLoan(ml), rate(r), owesBank(0.0) {}

BrassPlus::BrassPlus(const Brass ba, double ml , double r) : Brass(ba)
{
	maxLoan = ml;
	rate = r;
	owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
	Brass::ViewAcct();
	std::cout << "Limit debetu: " << maxLoan << std::endl;

	std::cout << "Kwota zadlu¿enia: " << owesBank << std::endl;

	std::cout << "Stopa oprocentowania: " << 100*rate << std::endl;
	
}

void BrassPlus::Withdraw(double amt)
{
	double bal=Balance();

	if (bal <= amt)
		Brass::Withdraw(amt);
	else if (bal <= amt + maxLoan)
	{
		Brass::Withdraw(bal);
		bal -= amt;
		owesBank = bal;
	}
	else
		std::cout << "Nie mo¿es wypo¿yczyæ piniedzy, przekracza limit debetu i posiadanej gotowki" << std::endl;
}

void enter(const int j, Brass **client)   //Ta Funkcja jak bedzie dzialaæ przerzuce do zasobow
{
	
	int wybor;
	std::string name, vorname;
	double begin, rate, max;
	long acc;

	for (int i = 0; i < j; i++)
	{
		cout << "Podaj 1 dla Brass, 2 dla BrassPlus:   ";
		while (!(cin >> wybor)&&(wybor==1||wybor==2))
		{
			
			cout << "zle dane kurna, riplej\n";
			cin.clear();
			cin.sync();
		}
		if (wybor != 1 || wybor != 2)

		cout << "Podaj imie i nazwisko:   ";
		while (!(cin >> name))
		{
			cout << "zle dane kurna, riplej\n";
			cin.clear();
			cin.sync();
		}
		while (!(cin >> vorname))
		{
			cout << "zle dane kurna, riplej\n";
			cin.clear();
			cin.sync();
		}
		name += " " + vorname;
		cout << std::endl;
		cout << "Podaj poczatkowy stan konta:   ";
		while (!(cin >> begin))
		{
			cout << "zle dane kurna, riplej\n";
			cin.clear();
			cin.sync();
		}
		cout << std::endl;
		cout << "Podaj Nr konta:   ";
		while (!(cin >> acc))
		{
			cout << "zle dane kurna, riplej\n";
			cin.clear();
			cin.sync();
		}
		cout << std::endl;
		if (wybor == 1)
		{
			client[i] = new Brass(name, acc, begin);
		}
		else if (wybor == 2)
		{
			cout << "Limit debetu:   ";
			cin >> max;
			cout << std::endl;
			cout << "Oprocentowanie:   ";
			cin >> rate;
			cout << std::endl;
			client[i] = new BrassPlus(name, acc, begin, max, rate);
		}
	}
}

void showAll(const int j,  Brass **client)
{
	for (int i = 0; i < j; i++)
	{
		client[i]->ViewAcct();
	}
}