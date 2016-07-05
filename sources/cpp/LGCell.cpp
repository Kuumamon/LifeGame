/*!
* \file LGCell.cpp
* \brief Cell implementation
* \author Alexis Koutero
* \version 0.1
*/

#include ".\..\header\LGCell.h"

/*** CONSTRUCTORS ***/
LGCell::LGCell() : m_isAlive(false) {}
LGCell::LGCell(bool IsAlive) : m_isAlive(IsAlive) {}
LGCell::LGCell(const LGCell& Cell) : m_isAlive(Cell.m_isAlive) {}

/*** ACCESSORS ***/
bool LGCell::isAlive() const {
	return m_isAlive;
}

void LGCell::setIsAlive(bool IsAlive) {
	m_isAlive = IsAlive;
}