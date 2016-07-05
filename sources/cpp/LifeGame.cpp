/*!
* \file LifeGame.cpp
* \brief Main for test
* \author Alexis Koutero
* \version 0.1
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include ".\..\header\LGCell.h"
#include ".\..\header\LGGrid.h"

using namespace std;

int main(){

	LGGrid* lg = 0;
	
	/*** INIT ***/
	srand(time(0));

	/*** TEST CODE***/
	//New 5*5 grid
	lg = new LGGrid();
	//lg->displayTech();
	//cout << endl;
	//lg->display();
	lg->setCellAlive(1, 2, true);
	lg->setCellAlive(2, 2, true);
	lg->setCellAlive(3, 2, true);
	lg->display();
	lg->execute();
	cout << endl;
	lg->display();
	lg->execute();
	cout << endl;
	lg->display();
	cout << endl;
	lg->displayStats();
	system("pause");

	/*** TERMINATE***/
	delete lg;
	return 0;
}