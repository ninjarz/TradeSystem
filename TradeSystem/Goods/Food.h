#ifndef _FOOD_H_
#define _FOOD_H_

#include "Goods.h"

//----------------------------------------------------------------------------------------------------
class Food : public Goods
{
public:
	Food();
	Food(const Food& _food);
	~Food();

private:
	int m_expiryDate;
	int m_productionDate;
	int m_depreciateDate;
	int m_depreciateFactor;

};

#endif