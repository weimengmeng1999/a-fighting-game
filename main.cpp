//=======================
//		main.cpp
//=======================

// main function for the RPG style game

#include <iostream>
#include <string>
#include<time.h>
using namespace std;

#include "swordsman.h"
#include "archer.h"
#include "mage.h"


int main()
{
	string tempName;
	string rolee;
	bool success = 0;		//flag for storing whether operation is successful
	cout << "Please input player's name: ";
	cin >> tempName;		// get player's name from keyboard input
	player *human;// use pointer of base class, convenience for polymorphism
	player *ai;
	int tempJob;		// temp choice for job selection
	char finish = 'a';


	while (finish == 'a')
	{
		finish = 'q';

		do
		{
			cout << "Please choose a job: 1 Swordsman, 2 Archer, 3 Mage" << endl;
			cin >> tempJob;
			system("cls");		// clear the screen
			switch (tempJob)
			{
			case 1:
				human = new swordsman(1, tempName);	// create the character with user inputted name and job
				success = 1;
				rolee = "swordsman";// operation succeed
				break;
			case 2:
				human = new archer(1, tempName);
				// create the character with user inputted name and job
				success = 1;
				rolee = "archer";
				break;
			case 3:
				human = new mage(1, tempName);	// create the character with user inputted name and job
				success = 1;
				rolee = "mage";
				break;
			default:
				break;				// In this case, success=0, character creation failed
			}
		} while (success != 1);		// so the loop will ask user to re-create a character

		int tempCom;			// temp command inputted by user
		int nOpp = 0;				// the Nth opponent
		for (int i = 1; nOpp < 5; i += 2)	// i is opponent's level
		{
			nOpp++;
			system("cls");
			cout << "STAGE" << nOpp << endl;
			cout << "Your opponent, a Level " << i << " ";
			printf("%s", rolee.c_str());
			system("pause");

			srand((unsigned)time(NULL));
			int a = rand() % 3;
			switch (a)
			{
			case 0:
				ai = new swordsman(1, "Warrior");
				break;
			case 1:
				ai = new archer(1, "Warrior");
				break;
			case 2:
				ai = new mage(1, "Warrior");
			default:
				break;
			}



			human->reFill();				// get HP/MP refill before start fight

			while (!human->death() && !ai->death())	// no died
			{
				success = 0;
				while (success != 1)
				{
					showinfo(*human, *ai);				// show fighter's information
					cout << "Please give command: " << endl;
					cout << "1 Attack; 2 Special Attack; 3 Use Heal; 4 Use Magic Water; 0 Exit Game" << endl;
					cin >> tempCom;
					switch (tempCom)
					{
					case 0:
						cout << "Are you sure to exit? Y/N" << endl;
						char temp;
						cin >> temp;
						if (temp == 'Y' || temp == 'y')
							return 0;
						else
							break;
					case 1:
						success = human->attack(*ai);
						human->isLevelUp();
						ai->isDead();
						break;
					case 2:
						success = human->specialatt(*ai);
						human->isLevelUp();
						ai->isDead();
						break;
					case 3:
						success = human->useHeal();
						break;
					case 4:
						success = human->useMW();
						break;
					default:
						break;
					}
				}
				if (!ai->death())		// If AI still alive
					ai->AI(*human);
				else							// AI died
				{
					cout << "YOU WIN" << endl;
					human->transfer(*ai);		// player got all AI's items
				}
				if (human->death())
				{
					system("cls");
					cout << endl << setw(50) << "GAME OVER" << endl;
					system("pause");
					cout << "input 'a' to play again, and input 'q' to quit";
					cin >> finish;
					if (finish=='a')
					{
						break;
					}
					// player is dead, program is getting to its end, what should we do here?
					else {
						return 0;
					}
				}
				if (finish == 'a')
				{
					break;
				}
			}
			if (finish == 'a')
			{
				break;
			}
		}
continue;
		cout << "input 'a' to play again, and input 'q' to quit";
		cin >> finish;
		if (finish == 'a')
		{
			continue;
		}
		else {
			// You win, program is getting to its end, what should we do here?
			system("cls");
			cout << "Congratulations! You defeated all opponents!!" << endl;
			system("pause");
			return 0;
		}
	}
}


