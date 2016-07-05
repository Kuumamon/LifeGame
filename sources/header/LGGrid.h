#ifndef DEF_LGGRID
#define DEF_LGGRID
#include "LGCell.h"

class LGGrid {
private:
	int m_xSize;
	int m_ySize;
	LGCell* m_cellGrid;

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

	void setCellAlive(int X, int Y, bool IsAlive);
};

#endif
