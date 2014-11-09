#ifndef _SUPPLIES_H_
#define _SUPPLIES_H_

#include "Goods.h"

//----------------------------------------------------------------------------------------------------
class Supplies : public Goods
{
public:
	Supplies();
	Supplies(const Supplies& _supplies);
	~Supplies();

private:
	int m_expiryDate;
};

#endif