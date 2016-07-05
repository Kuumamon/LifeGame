#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include "LGCell.h"
#include "LGGrid.h"

using namespace std;

int main(){

	LGGrid lg;
	
	/*** INIT ***/
	srand(time(0));

	/*** TEST CODE***/
	lg.setCellAlive(5, 5, true);
	if (lg.isCellAlive(5, 5)) {
		cout << "Is alive" << endl;
	}
	system("pause");
	return 0;
}
