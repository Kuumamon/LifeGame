#include "LGGrid.h"

/*** CONSTRUCTORS ***/
LGGrid::LGGrid() {
	m_xSize = 5;
	m_ySize = 5;
	//Call default constructor for LGCell
	m_cellGrid = new LGCell[m_xSize*m_ySize];

	//Randomize
}
LGGrid::LGGrid(int const XSize, int const YSize) {}
LGGrid::LGGrid(const LGGrid& Grid) {}

/*** DESTRUCTOR ***/
LGGrid::~LGGrid() {
	delete[] m_cellGrid;
}

/*** ACCESSOR ***/
int LGGrid::getXSize() const{
	return m_xSize;
}

int LGGrid::getYSize() const {
	return m_ySize;
}

bool LGGrid::isCellAlive(int X, int Y) const {
	return m_cellGrid[X*m_xSize + Y].isAlive();
}

void LGGrid::setCellAlive(int X, int Y, bool IsAlive) {
	m_cellGrid[X*m_xSize + Y].setIsAlive(IsAlive);
}
