#ifndef DEF_LGGRID
#define DEF_LGGRID

/*!
* \file LGGrid.h
* \brief Grid definition
* \author Alexis Koutero
* \version 0.1
*/

#include "LGCell.h"

/*! \class LGCell
* \brief Class managing a grod of cells and it's behavior
*/
class LGGrid {
private:
	int m_xTechSize; /*!< Current number of line of the board including empty lines*/
	int m_yTechSize; /*!< Current number of column of the board including empty lines*/
	int m_xRealSize; /*!< Number of line of the board*/
	int m_yRealSize; /*!< Number of column of the board*/
	LGCell* m_cellGrid; /*!< The board*/

	int m_totalAliveCells; /*!< Number of curent alive cells*/
	int m_totalDeath; /*!< Number of cell which passed away*/
	int m_totalBirth; /*!< Number of cell which had borne*/
	int m_totalExecution; /*!< Number of life cycle*/

	/*! \brief return a copy of the current grid
	*
	* \return a pointer to the new grid
	*/
	LGGrid* copyGrid();

	/*! \brief Copy the grid into the current
	*
	* \param LGGrid : Crid to copy
	*/
	void updateGrid(LGGrid const * Grid);

public:
	/*! \brief Defaul constructor
	*
	* Default size is 5 by 5 grid is all cells dead
	*/
	LGGrid();

	/*! \brief Constructor to build a specific sized grid
	*
	* All cells are dead
	*
	* \param XSize : number of line without empty ones
	* \param YSize : number of column without empty ones
	*/
	LGGrid(int XSize, int YSize);

	/*! \brief Copy constructor
	*
	* \param Grid : creates a new grid based on the parameter
	*/
	LGGrid(const LGGrid&  Grid);

	/*! \brief Destructor
	*
	* Desallocates grid and cells.
	*/
	~LGGrid();

	/*! \brief Return number of line
	*
	* \return number of line without empty ones
	*/
	int getXSize() const;

	/*! \brief Return number of column
	*
	* \return number of column without empty ones
	*/
	int getYSize() const;

	/*! \brief Is a cell alive?
	*
	* Check if a cell is alive or not. Manage empty cells therefore parameters should be as for the real grid only
	*
	* \param X : line position
	* \param Y : column position
	* \return true if the cell is alive
	*/
	bool isCellAlive(int X, int Y) const;

	/*! \brief How many cells are alive?
	*
	* \return : total number of alive cells on the current grid
	*/
	int getTotalAliveCells() const;

	/*! \brief Change cell's status
	*
	* \param X : line position
	* \param Y : column position
	*/
	void setCellAlive(int X, int Y, bool IsAlive);

	/*! \brief Execute on turn of the game
	*/
	void execute();

	/*! \brief Dispays on stdout all cells
	*/
	void display() const;

	/*! \brief display on stdout all cells including empty edges
	*/
	void displayTech() const;

	/*! \brief display current grid's stats
	*
	* Current stats are :
	*	- Grid size
	*	- Total cells
	*	- Total alive cells
	*	- Number of execution
	*	- Number of death
	*	- Number of birth
	*/
	void displayStats() const;

	/*! \brief update statistics.
	*
	* Current stats are :
	*	- Grid size
	*	- Total cells
	*	- Total alive cells
	*	- Number of execution
	*	- Number of death
	*	- Number of birth
	*/
	void updateStats();
};

#endif