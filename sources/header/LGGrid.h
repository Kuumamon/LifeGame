#ifndef DEF_LGGRID
#define DEF_LGGRID
#include "LGCell.h"

class LGGrid {
private:
	int m_xTechSize;
	int m_yTechSize;
	int m_xRealSize;
	int m_yRealSize;
	LGCell* m_cellGrid;

	/*** For stats***/
	int m_totalAliveCells;
	int m_totalDeath;
	int m_totalBirth;
	int m_totalExecution;

	/*** LIFE GAME ENGINE ***/
	LGGrid* copyGrid();
	void updateGrid(LGGrid const * Grid);

public:
	/*** CONSTRUCTORS ***/
	LGGrid();
	LGGrid(int XSize, int YSize);
	LGGrid(const LGGrid&  Grid);

	/*** DESTRUCTOR ***/
	~LGGrid();

	/*** ACCESSOR ***/
	int getXSize() const;
	int getYSize() const;
	bool isCellAlive(int X, int Y) const;
	int getTotalAliveCells() const;

	void setCellAlive(int X, int Y, bool IsAlive);

	/*** LIFE GAME ENGINE ***/
	void execute();

	/*** OTHERS ***/
	void display() const;
	void displayTech() const;
	void displayStats() const;
	void updateStats();
};

#endif