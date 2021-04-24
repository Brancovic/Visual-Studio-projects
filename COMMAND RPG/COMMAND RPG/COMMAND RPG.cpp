// COMMAND RPG.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <string>
#include <iostream>
using namespace std;

string P1;
int HPp1 = 100;
int DMGp1 = 10;
string P2;
int HPp2 = 100;
int DMGp2 = 10;
int P1schose;
int P2schose;
string Start;
int x = 0;
int Healp1 = 0;
int Healp2 = 0;


int main()
{

	// Uvítacie pole
	cout << "Welcome to Command RPG. Type Start and Press enter to start" << endl;
	cin >> Start;
	cout << endl;

	if (1 > 0)
		//vyberanie mien

		//hráč č.1 si vyberá meno
		string P1;
	cout << "Name of Player1 " << endl;
	cin >> P1;
	cout << endl;

	//hráč č.2 si vyberá meno
	cout << "Name of Player2 " << endl;
	cin >> P2;
	cout << endl;

	//toto je príkaz na zobrazenie štatistýk, stačí ho kopírovať
	cout << "	stats:" << "P1 Name: " << P1 << "    HP:" << HPp1 << "    Damage:" << DMGp1 << endl;
	cout << endl;
	cout << "	stats:" << "P2 Name: " << P2 << "    HP:" << HPp2 << "    Damage:" << DMGp2 << endl;
	cout << endl;
	cout << endl;
	// tu začína loop 

	do
	{
		//Hra 1. hráč je na ťahu 
		cout << P1 << " is on turn. schose from hit-1 heal-2" << endl;
		cin >> P1schose;
		cout << endl;

		//Tu je rozhodovanie
		switch (P1schose)
		{

		case 1: "hit";

			cout << P2 << " was hitted -10HP    " << endl;
			*&HPp2 = HPp2 - 10;
			cout << endl;

			//toto je príkaz na zobrazenie štatistýk, stačí ho kopírovať
			cout << "	stats:" << "P1 Name: " << P1 << "    HP:" << HPp1 << "    Damage:" << DMGp1 << endl;
			cout << endl;
			cout << "	stats:" << "P2 Name: " << P2 << "    HP:" << HPp2 << "    Damage:" << DMGp2 << endl;
			cout << endl;
			cout << endl;
			break;

		case 2: "heal";

			if (Healp1 >= 3) {
				cout << "You used too much heal you can not heal more" << endl;
				break;
			}

			*&HPp1 = HPp1 + 20;
			cout << P1 << " was healed +20Hp    " << P1 << " have " << "Hp" << HPp1 << endl;
			cout << endl;
			Healp1++;
			cout << Healp1;

			//toto je príkaz na zobrazenie štatistýk, stačí ho kopírovať
			cout << "	stats:" << "P1 Name: " << P1 << "    HP:" << HPp1 << "    Damage:" << DMGp1 << endl;
			cout << endl;
			cout << "	stats:" << "P2 Name: " << P2 << "    HP:" << HPp2 << "    Damage:" << DMGp2 << endl;
			cout << endl;
			cout << endl;

			break;
		}

		//Hra 2. hráč je na ťahu 
		cout << P2 << " is on turn. schose from hit-1 heal-2" << endl;
		cin >> P2schose;
		cout << endl;

		//Tu je 2. rozhodovanie
		switch (P2schose)
		{
		case 1: "hit";
			cout << P1 << " was hitted -10HP    " << endl;
			*&HPp1 = HPp1 - 10;
			cout << endl;

			//toto je príkaz na zobrazenie štatistýk, stačí ho kopírovať
			cout << "	stats:" << "P1 Name: " << P1 << "    HP:" << HPp1 << "    Damage:" << DMGp1 << endl;
			cout << endl;
			cout << "	stats:" << "P2 Name: " << P2 << "    HP:" << HPp2 << "    Damage:" << DMGp2 << endl;
			cout << endl;
			cout << endl;
			break;

		case 2: "heal";

			if (Healp2 >= 3) {
				cout << "You used too much heal you can not heal more" << endl;
				break;
			}

			*&HPp2 = HPp2 + 20;
			cout << P2 << " was healed +20Hp    " << P1 << " have " << "Hp" << HPp1 << endl;
			cout << endl;

			//toto je príkaz na zobrazenie štatistýk, stačí ho kopírovať
			cout << "	stats:" << "P1 Name: " << P1 << "    HP:" << HPp1 << "    Damage:" << DMGp1 << endl;
			cout << endl;
			cout << "	stats:" << "P2 Name: " << P2 << "    HP:" << HPp2 << "    Damage:" << DMGp2 << endl;
			cout << endl;
			cout << endl;
			break;
		}
	} while (HPp1 >= 10 || HPp2 >= 10);

	cout << "Thank for playing!" << endl;

	return 0;
};