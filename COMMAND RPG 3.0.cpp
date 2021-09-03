#include <iostream>
#include <Windows.h>
#include <algorithm>


using namespace std;


string Player1;
string Player2;

//HP
int HPP1 = 100;
int HPP2 = 100;

//demage
int DmgP1 = 10;
int DmgP2 = 10;

//odpoveï
string P1Answer;
string P2Answer;
string Attack = "attack";
string Heal = "heal";

/*color

	#define color_black      0
	#define color_dark_blue  1
	#define color_dark_green 2
	#define color_light_blue 3
	#define color_dark_red   4
	#define color_magenta    5
	#define color_orange     6
	#define color_light_gray 7
	#define color_gray       8
	#define color_blue       9
	#define color_green     10
	#define color_cyan      11
	#define color_red       12
	#define color_pink      13
	#define color_yellow    14
	#define color_white     15

	colors are 0=black 1=blue 2=green and so on to 15=white  
	colorattribute = foreground + background * 16
	 to get red text on yellow use 4 + 14*16 = 228
	 light red on yellow would be 12 + 14*16 = 236
*/

HANDLE  hConsole;

//changing color of console
void SetConsoleColor(int txtcolor, int BGcolor) {

	int finalcolor;

	if (BGcolor == 0) {

			finalcolor = txtcolor;
	}

	else {

	finalcolor = txtcolor + BGcolor*16;

	}


		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, finalcolor);
}

//function for picking name of players
void namePickingF() {

	SetConsoleColor(30,0);

	cout << "Enter name of the first Player: ";
	cin >> Player1;

	cout << "Enter name of the second Player: ";
	cin >> Player2;

};
	
//function for didplaying stats
void statsDisplayF() {
	
	cout << "   P1	Name: " << Player1 << "  HP: " << HPP1 << "  Demage:" << DmgP1<< endl;
	cout << "   P2	Name: " << Player2 << "  HP: " << HPP2 << "  Demage:" << DmgP2 << endl;
	cout << endl;
}

//this is funtion of attack for P1 make function for P2
void AttackF(string HittingP){
	
	if (HittingP == Player1) {
		cout << Player1 << " wasd hitted " << Player2 << " for " << DmgP1 << endl;
		*&HPP2 = HPP2-DmgP1;
		cout << endl;
	}

	else {
		cout << Player2 << " was hitted " << Player1 << " for " << DmgP2 << endl;
		*&HPP1 = HPP1 - DmgP2;
		cout << endl;
	}
}

//
void HealF(string Player) {
	int HealCountP1 = 0;
	int HealCountP2 = 0;

	if (Player == Player1) {

		if (HealCountP1 <= 3) {

			HealCountP1++;
			cout << Player1 << " was healed for 30 HP";
			*&HPP1 = HPP1 + 30;
			cout << endl;
		}
		else
		{
			cout << Player1 << " has been heald too much you can't heal no more";
			cout << endl;
		}
	}

	if (Player == Player2) {

		if (HealCountP2 <= 3) {

			HealCountP2++;
			cout << Player2 << " was healed for 30 HP";
			*&HPP2 = HPP2 + 30;
			cout << endl;
		}
		else
		{
			cout << Player2 << " has been heald too much you can't heal no more";
			cout << endl;
		}
	}
}

//defend function of P1
void DefendF() {




}

//Crit. attack function for P1
void CritAttackF() {




}

void LowerCasingF(string string){
	
	if (string == P1Answer) {

		std::for_each(P1Answer.begin(), P1Answer.end(), [](char& c) {
			c = ::tolower(c);
		});
	}

	else if  (string == P2Answer){

		std::for_each(P2Answer.begin(), P2Answer.end(), [](char& c) {
			c = ::tolower(c);
		});
	}
}

void Error(string ErrorMessage) {

	SetConsoleColor(12,0);
	cout << "ERROR" << endl;
	cout << ErrorMessage << endl;
	cout << "ERROR" << endl;
	cout << endl;
	SetConsoleColor(15, 0);

}



int main() {

	SetConsoleColor(3,15);
	
	cout << "Welcome to COMMAND RPG ";
	system("pause");
	
	namePickingF();

	cout << endl;
	cout << Player1 << endl;
	cout << Player2 << endl;
	cout << endl;

	statsDisplayF();

	do
	{

		cout << Player1 << " is on turn. type Attack or Heal: ";
		cin >> P1Answer;
		cout << endl;

		LowerCasingF(P1Answer);

		if (P1Answer == Attack) {
		AttackF(Player1);
		}

		else if (P1Answer == Heal)
		{
			HealF(Player1);
		}

		else
		{
			Error("Answer P1 not found");
		}

		statsDisplayF();

		LowerCasingF(P2Answer);
	
		if ( P2Answer == Attack) {

			AttackF(Player2);

		}

		else if (P2Answer == Heal)
		{
			HealF(Player2);
		}
		
		else
		{
			Error("Answer P1 not found");
		}


	} while (HPP1 >= 0 || HPP2 >= 0);
	
}