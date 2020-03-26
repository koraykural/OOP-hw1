#include "OrderList.h"
#include <iostream>
#include <string>

using namespace std;

void printWelcome()
{
	cout << " __        __   _                          " << endl;
	cout << " \\ \\      / /__| | ___ ___  _ __ ___   ___ " << endl;
	cout << "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ " << endl;
	cout << "   \\ V  V /  __/ | (_| (_) | | | | | |  __/" << endl;
	cout << "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|" << endl;
	cout << endl << "1. Add an order";
	cout << endl << "2. List orders";
	cout << endl << "3. Deliver an order";
	cout << endl << "4. Exit" << "\n\n";
}

int main()
{
	OrderList list;
	bool programWorking = true;
	int function = 0;

	while(programWorking)
	{
		printWelcome();

		cout << "Choose what to do: ";
		cin >> function;

		switch (function)
		{
		case 1:
			list.takeOrder();
			break;
		case 2:
			list.listOrders();
			break;
		case 3:
			list.deliverOrders();
			break;
		case 4:
			programWorking = false;
			cout << "Goodbye!" << endl;
			break;
		default:
			cerr << "Invalid input! Try again." << endl;
			break;
		}
	}

	return 0;
}