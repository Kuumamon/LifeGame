#include ".\..\header\LGGrid.h"

/*** CONSTRUCTORS ***/
LGGrid::LGGrid() {
	int isAlive;

	m_xTechSize = 7;
	m_yTechSize = 7;
	m_xRealSize = 5;
	m_yRealSize = 5;
	m_totalAliveCells = 0;
	m_totalDeath = 0;
	m_totalBirth = 0;
	m_totalExecution = 0
	//include empty edges
	//Call automatically default constructor for LGCell
	m_cellGrid = new LGCell[m_xTechSize*m_yTechSize];

	//Randomize
	/*for (int i = 0; i < m_xRealSize; i++) {
		for (int j = 0; j < m_yRealSize; j++) {
			isAlive = rand() % 2;
			if (isAlive == 1) {
				this->setCellAlive(i, j, true);
				m_totalAliveCells++;
			}
		}
	}*/
}
LGGrid::LGGrid(int const XSize, int const YSize) :
	m_xTechSize(XSize + 1),
	m_yTechSize(YSize + 1),
	m_xRealSize(XSize + 1),
	m_yRealSize(YSize + 1),
	m_totalAliveCells(0),
	m_totalDeath(0),
	m_totalBirth(0),
	m_totalExecution(0) {
	m_cellGrid = new LGCell[m_xTechSize * m_yTechSize];
}
LGGrid::LGGrid(const LGGrid& Grid){}

/*** DESTRUCTOR ***/
LGGrid::~LGGrid() {
	delete[] m_cellGrid;
}

/*** ACCESSOR ***/
int LGGrid::getXSize() const{
	return m_xRealSize;
}

int LGGrid::getYSize() const{
	return m_yRealSize;
}

//This method manage indexes translation, parameters are for a normal tab and start at 0.
bool LGGrid::isCellAlive(int X, int Y) const{
	return m_cellGrid[(X + 1) * m_xTechSize + Y + 1].isAlive();
}

int LGGrid::getTotalAliveCells() const{
	return m_totalAliveCells;
}

//This method manage indexes translation, parameters are for a normal tab and start at 0.
void LGGrid::setCellAlive(int X, int Y, bool IsAlive) {
	m_cellGrid[(X + 1)*m_xTechSize + Y + 1].setIsAlive(IsAlive);
}

/*** LIFE GAME ENGINE ***/
void LGGrid::execute() {
	LGGrid* tempGrid = 0;
	int nCells = 0; //alive surrounding cells

	//new tempGrid used as source on odd turns
	tempGrid = this->copyGrid();
	
	for (int i = 0; i < m_xRealSize; i++) {
		for (int j = 0; j < m_yRealSize; j++) {
			nCells = 0;
			for (int x = i - 1; x <= i + 1; x++) {
				for (int y = j - 1; y <= j + 1; y++) {
					if (!(x == i && y == j) && this->isCellAlive(x, y) == true) {
						nCells++;
					}
				}
			}
			//birth if 3 living cells, living on if 2 or 3 living, else dies
			if (this->isCellAlive(i, j) == false && nCells == 3) {
				tempGrid->setCellAlive(i, j, true);
				m_totalBirth++;
			} else if (this->isCellAlive(i, j) == true && (nCells == 2 || nCells == 3)) {
				//unnecessary?
				tempGrid->setCellAlive(i, j, true);
			} else if (this->isCellAlive(i, j) == true) {
				tempGrid->setCellAlive(i, j, false);
				m_totalDeath++;
			}
		}
	}

	//upgrade this with final grid
	this->updateGrid(tempGrid);
	//stats
	m_totalExecution++;
	this->updateStats();
	delete tempGrid;
}

LGGrid* LGGrid::copyGrid() {
	LGGrid* newGrid = 0;

	newGrid = new LGGrid(m_xTechSize, m_yTechSize);

	for (int i = 0; i < m_xRealSize; i++) {
		for (int j = 0; j < m_yRealSize; j++) {
			if (this->isCellAlive(i, j) == true) {
				newGrid->setCellAlive(i, j, true);
			}
		}
	}
	return newGrid;
}

void LGGrid::updateGrid(LGGrid const* Grid) {
	for (int i = 0; i < m_xRealSize; i++) {
		for (int j = 0; j < m_yRealSize; j++) {
			if (Grid->isCellAlive(i, j) == true) {
				this->setCellAlive(i, j, true);
			} else {
				this->setCellAlive(i, j, false);
			}
		}
	}
}

/*** OTHERS ***/
void LGGrid::display() const {
	for (int i = 0; i < m_xRealSize; i++) {
		for (int j = 0; j < m_yRealSize; j++) {
			std::cout << (this->isCellAlive(i, j) == true ? "1" : "0");
		}
		std::cout << std::endl;
	}
}

void LGGrid::displayTech() const {
	for (int i = 0; i < m_xTechSize; i++) {
		for (int j = 0; j < m_yTechSize; j++) {
			std::cout << (m_cellGrid[i*m_xTechSize + j].isAlive() == true ? "1" : "0");
		}
		std::cout << std::endl;
	}
}

void LGGrid::displayStats() const {
	std::cout << "Grid size: " << m_xRealSize << "*" << m_yRealSize << std::endl;
	std::cout << "Total cells: " << m_xRealSize*m_yRealSize << std::endl;
	std::cout << "Total alive cells: " << m_totalAliveCells << std::endl;
	std::cout << "Total execution: " << m_totalExecution << std::endl;
	std::cout << "Total death: " << m_totalDeath << std::endl;
	std::cout << "Total birth: " << m_totalBirth << std::endl;
}

void LGGrid::updateStats() {
	m_totalAliveCells = 0;
	for (int i = 0; i < m_xRealSize; i++) {
		for (int y = 0; y < m_xRealSize; j++) {
			if (this->isCellAlive(i, j) == true) m_totalAliveCells++;
		}
	}
}