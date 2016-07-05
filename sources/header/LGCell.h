#ifndef DEF_LGCELL
#define DEF_LGCELL

/*!
* \file LGCell.h
* \brief Cell definition
* \author Alexis Koutero
* \version 0.1
*/

#include <iostream>

/*! \class LGCell
* \brief Class representing a cell
*/
class LGCell {
private:
	bool m_isAlive; /*!< Cell's status*/

public:
	/*!
	*  \brief Default constructor
	*/
	LGCell();

	/*!
	*  \brief Constructor with parameters
	*
	*  \param IsAlive : if true, the cell is setted as alive
	*/
	LGCell(bool IsAlive);
	LGCell(const LGCell& Cell);

	/*!
	*  \brief Is this cell alive?
	*/
	bool isAlive() const;

	/*!
	*  \brief Modify cell's status
	*
	*  \param IsAlive : if true, the cell is setted as alive
	*/
	void setIsAlive(bool IsAlive);
};
#endif
