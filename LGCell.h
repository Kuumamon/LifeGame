#ifndef DEF_LGCELL
#define DEF_LGCELL

#include <iostream>

class LGCell {
private:
	bool m_isAlive;

public:
	/*** CONSTRUCTORS ***/
	LGCell();
	LGCell(bool IsAlive);
	LGCell(const LGCell& Cell);

	/*** ACCESSORS ***/
	bool isAlive() const;
	void setIsAlive(bool IsAlive);
};
#endif
