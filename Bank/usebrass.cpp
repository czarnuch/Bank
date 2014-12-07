#include "brass.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::cin;

int main()
{
	cout << "Witaj w banku Wshodnio-Zachodnim powiedz ilu bedziesz mieæ klientow\n\n";
	int numberClients;
	
	while (!(cin >> numberClients))
	{
		cout << "Podales zle dana";
		cin.clear();
		cin.sync();

	}

	Brass * clients = new Brass[numberClients];
	enter(numberClients, &clients);
	showAll(numberClients, &clients);
	
	
	cin.sync();
	cin.get();

}
